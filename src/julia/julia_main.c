/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:51:23 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/05 21:11:18 by mmousson         ###   ########.fr       */
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

void		julia_generate(void *params)
{
	float				zoom_x;
	float				zoom_y;
	float				z_r;
	float				z_i;
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
			z_r = ((float)(inf->x) / zoom_x) - -(inf->limits.right);
			z_i = ((float)(inf->y) / zoom_y) - -(inf->limits.down);
			render(z_r, z_i, inf->iterations_max, inf);
		}
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img_v, 0, 0);
}

void		ft_julia(t_fractol *inf)
{
	inf->update = julia_generate;
	inf->limits.up = 1.0f;
	inf->limits.down = -1.0f;
	inf->limits.left = 1.0f;
	inf->limits.right = -1.0f;
	inf->iterations_max = 25;
	julia_generate((void *)inf);
	mlx_hook(inf->win, 4, 0, &mouse_press, (void *)inf);
	mlx_key_hook(inf->win, &key_manager, (void *)inf);
	mlx_loop(inf->mlx);
}
