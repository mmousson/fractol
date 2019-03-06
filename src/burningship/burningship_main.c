/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:55:21 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/06 01:01:45 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

static int	loop(double *z_r, double *z_i, double *c_r, double *c_i)
{
	double	tmp;

	tmp = *z_r;
	*z_r = (*z_r * *z_r) - (*z_i * *z_i) + *c_r;
	*z_i = ft_fabs((2.0 * *z_i * tmp)) + *c_i;
	return (1);
}

static void	render(double c_r, double c_i, int itermax, t_fractol *inf)
{
	int		i;
	double	z_r;
	double	z_i;
	double	mu;

	i = 0;
	z_r = 0.0f;
	z_i = 0.0f;
	while ((z_r * z_r) + (z_i * z_i) < 4.0f && i < itermax)
		i += loop(&z_r, &z_i, &c_r, &c_i);
	if (i == itermax)
		ft_put_pixel(inf->image, inf->x, inf->y, 0x000000);
	else
	{
		i += loop(&z_r, &z_i, &c_r, &c_i);
		i += loop(&z_r, &z_i, &c_r, &c_i);
		mu = (double)i + 1.0 - (log2(log2(z_r * z_r + z_i * z_i))) + 4.0;
		ft_put_pixel(inf->image, inf->x, inf->y,
			ft_clerp(0xFF0000, 0xFFFFFF, inf->iterations_max / mu));
	}
}

void		burningship_generate(void *params)
{
	double				zoom_x;
	double				zoom_y;
	double				c_r;
	double				c_i;
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
			c_r = ((double)(inf->x) / zoom_x) - -(inf->limits.right);
			c_i = ((double)(inf->y) / zoom_y) - -(inf->limits.down);
			render(c_r, c_i, inf->iterations_max, inf);
		}
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img_v, 0, 0);
}

void		ft_burningship(t_fractol *inf)
{
	inf->update = burningship_generate;
	inf->limits.up = 1.2;
	inf->limits.down = -1.2;
	inf->limits.left = 0.6;
	inf->limits.right = -2.1;
	inf->iterations_max = 25;
	burningship_generate((void *)inf);
	mlx_hook(inf->win, 4, 0, &mouse_press, (void *)inf);
	mlx_key_hook(inf->win, &key_manager, (void *)inf);
	mlx_loop(inf->mlx);
}
