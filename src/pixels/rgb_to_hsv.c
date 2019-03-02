/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hsv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:54:07 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 00:32:32 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdio.h>

static double	hue(double r_prime, double g_prime, double b_prime)
{
	double	delta;
	double	c_max;
	double	c_min;

	c_max = ft_max(ft_max(r_prime, g_prime), b_prime);
	c_min = ft_min(ft_min(r_prime, g_prime), b_prime);
	delta = c_max - c_min;
	if (delta == 0.0L)
		return (0.0L);
	else if (c_max == r_prime)
		return ((g_prime - b_prime) / delta + ((g_prime < b_prime) ? 6 : 0));
	else if (c_max == g_prime)
		return ((b_prime - r_prime) / delta + 2.0L);
	else
		return ((r_prime - g_prime) / delta + 4.0L);
}

static double	saturation(double r_prime, double g_prime, double b_prime)
{
	double	c_max;
	double	c_min;
	double	delta;

	c_max = ft_max(ft_max(r_prime, g_prime), b_prime);
	c_min = ft_min(ft_min(r_prime, g_prime), b_prime);
	delta = c_max - c_min;
	if (c_max == 0)
		return (0.0L);
	else
		return (delta / c_max);
}

t_hsv_color		rgb_to_hsv(int rgb_color)
{
	double		r_prime;
	double		g_prime;
	double		b_prime;
	t_hsv_color	result;

	r_prime = (double)((rgb_color & 0xFF0000) >> 16) / 255.0L;
	g_prime = (double)((rgb_color & 0x00FF00) >> 8) / 255.0L;
	b_prime = (double)(rgb_color & 0x0000FF) / 255.0L;
	result.hue = hue(r_prime, g_prime, b_prime);
	result.saturation = saturation(r_prime, g_prime, b_prime);
	result.value = ft_max(ft_max(r_prime, g_prime), b_prime);
	return (result);
}

// int				main(void)
// {
// 	int r = 112;
// 	int g = 67;
// 	int b = 12;

// 	t_hsv_color res = rgb_to_hsv((r << 16) | (g << 8) | b);
// 	printf("H = %lf\n", res.hue);
// 	printf("S = %lf\n", res.saturation);
// 	printf("V = %lf\n", res.value);
// 	return (0);
// }
