/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:51:23 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 11:45:00 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

static void	render(float z_r, float z_i, int itermax, t_fractol *inf)
{
	int		i;
	float	c_r;
	float	c_i;
	float	tmp;

	i = 0;
	c_r = 0.23f;
	c_i = 0.76f;
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
			ft_clerp(0x000000, 0xFF00FF, (double)i / (double)itermax));
}

void		ft_julia(t_fractol *inf)
{
	int					iterations_max;
	float				zoom_x;
	float				zoom_y;
	float				z_r;
	float				z_i;

	inf->x = -1;
	iterations_max = 50;
	zoom_x = (float)WIDTH / (1.0f - -1.0f);
	zoom_y = (float)HEIGHT / (1.0f - -1.0f);
	while (++(inf->x) < WIDTH)
	{
		inf->y = -1;
		while (++(inf->y) < HEIGHT)
		{
			z_r = ((float)(inf->x) / zoom_x) - 1.0f;
			z_i = ((float)(inf->y) / zoom_y) - 1.0f;
			render(z_r, z_i, iterations_max, inf);
		}
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img_v, 0, 0);
	mlx_hook(inf->win, 4, 0, &mandelbrot_mouse_press, (void *)inf);
	mlx_key_hook(inf->win, &mandelbrot_key_manager, (void *)inf);
	mlx_loop(inf->mlx);
}
