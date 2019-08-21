/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:51:23 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/11 19:54:24 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"

static double	loop(double *z_r, double *z_i, double *c_r, double *c_i)
{
	double	tmp;

	tmp = *z_r;
	*z_r = (*z_r * *z_r) - (*z_i * *z_i) + *c_r;
	*z_i = (2.0 * *z_i * tmp) + *c_i;
	return (exp(-sqrt((*z_r * *z_r) + (*z_i * *z_i))));
}

static void		render(double z_r, double z_i, int itermax, t_fractol *inf)
{
	int		i;
	double	c_r;
	double	c_i;
	double	mu;

	i = 0;
	c_r = inf->params.c_r;
	c_i = inf->params.c_i;
	mu = exp(-sqrt((z_r * z_r) + (z_i * z_i)));
	while ((z_r * z_r) + (z_i * z_i) < 4.0 && i++ < itermax)
		mu += loop(&z_r, &z_i, &c_r, &c_i);
	if (i == itermax)
		ft_put_pixel(inf->image, inf->x, inf->y, 0x000000);
	else
	{
		mu += loop(&z_r, &z_i, &c_r, &c_i);
		ft_put_pixel(inf->image, inf->x, inf->y,
			ft_clerp(0x0000FF, 0xFFFFFF, (double)itermax / mu));
	}
}

void			julia_generate(void *params)
{
	double				zoom_x;
	double				zoom_y;
	double				z_r;
	double				z_i;
	t_fractol			*inf;

	inf = (t_fractol *)params;
	inf->x = -1;
	zoom_x = (double)WIDTH / (inf->limits.left - inf->limits.right);
	zoom_y = (double)HEIGHT / (inf->limits.up - inf->limits.down);
	while (++(inf->x) < WIDTH)
	{
		inf->y = -1;
		while (++(inf->y) < HEIGHT)
		{
			z_r = ((double)(inf->x) / zoom_x) - -(inf->limits.right);
			z_i = ((double)(inf->y) / zoom_y) - -(inf->limits.down);
			render(z_r, z_i, inf->iterations_max, inf);
		}
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img_v, 0, 0);
}

void			ft_julia(t_fractol *inf)
{
	inf->update = julia_generate;
	inf->limits.up = 1.0;
	inf->limits.down = -1.0;
	inf->limits.left = 1.0;
	inf->limits.right = -1.0;
	inf->iterations_max = 25;
	julia_generate((void *)inf);
	mlx_hook(inf->win, MOUSE_PRESS, 0, &mouse_press, (void *)inf);
	mlx_hook(inf->win, MOUSE_MOVE, 0, &mouse_move, (void *)inf);
	mlx_key_hook(inf->win, &key_manager, (void *)inf);
	mlx_loop(inf->mlx);
}
