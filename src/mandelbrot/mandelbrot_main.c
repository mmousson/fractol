/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:55:21 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 07:07:55 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ft_clerp(0x000000, 0xFFFFFF, (double)i * 3 / (double)itermax));
}

void		ft_mandelbrot(t_fractol *inf)
{
	int					iterations_max;
	float				zoom_x;
	float				zoom_y;
	float				c_r;
	float				c_i;

	inf->x = -1;
	iterations_max = 20;
	zoom_x = (float)WIDTH / (0.6f - -2.1f);
	zoom_y = (float)HEIGHT / (1.2f - -1.2f);
	while (++(inf->x) < WIDTH)
	{
		inf->y = -1;
		while (++(inf->y) < HEIGHT)
		{
			c_r = ((float)(inf->x) / zoom_x) - 2.1f;
			c_i = ((float)(inf->y) / zoom_y) - 1.2f;
			render(c_r, c_i, iterations_max, inf);
		}
	}
}
