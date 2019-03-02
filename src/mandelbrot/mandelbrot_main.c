/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:55:21 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 11:44:54 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

static void	render(float c_r, float c_i, int itermax, t_fractol *inf)
{
	int		i;
	float	z_r;
	float	z_i;
	float	tmp;

	i = 0;
	z_r = 0.0f;
	z_i = 0.0f;
	while ((z_r * z_r) + (z_i * z_i) < 4.0f && i < itermax)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = (2 * z_i * tmp) + c_i;
		i++;
	}
	if (i == itermax)
		ft_put_pixel(inf->image, inf->x, inf->y, 0x000000);
	else
		ft_put_pixel(inf->image, inf->x, inf->y,
			ft_clerp(0x000000, 0xFF0000, (double)i / (double)itermax));
}

void		mandelbrot_generate(void *params)
{
	float				zoom_x;
	float				zoom_y;
	float				c_r;
	float				c_i;
	t_fractol			*inf;

	inf = (t_fractol *)params;
	inf->x = -1;
	zoom_x = (float)WIDTH / (inf->limits.left - inf->limits.right);
	zoom_y = (float)HEIGHT / (inf->limits.up - inf->limits.down);
	while (++(inf->x) < WIDTH)
	{
		inf->y = -1;
		while (++(inf->y) < HEIGHT)
		{
			c_r = ((float)(inf->x) / zoom_x) - -(inf->limits.right);
			c_i = ((float)(inf->y) / zoom_y) - -(inf->limits.down);
			render(c_r, c_i, inf->iterations_max, inf);
		}
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img_v, 0, 0);
}

void		ft_mandelbrot(t_fractol *inf)
{
	inf->limits.up = 1.2f;
	inf->limits.down = -1.2f;
	inf->limits.left = 0.6f;
	inf->limits.right = -2.1f;
	inf->iterations_max = 25;
	mandelbrot_generate((void *)inf);
	mlx_hook(inf->win, 4, 0, &mandelbrot_mouse_press, (void *)inf);
	mlx_key_hook(inf->win, &mandelbrot_key_manager, (void *)inf);
	mlx_loop(inf->mlx);
}
