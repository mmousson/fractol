/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hsl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:33:14 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/06 00:29:19 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

static double	hue(double delta, double r_p, double g_p, double b_p)
{
	double	res;
	double	c_max;

	c_max = ft_dmax(3, r_p, g_p, b_p);
	if (delta == 0.0)
		res = 0.0;
	else if (c_max == r_p)
		res = (g_p - b_p) / delta;
	else if (c_max == g_p)
		res = (b_p - r_p) / delta + 2.0;
	else
		res = (r_p - g_p) / delta + 4.0;
	res *= 60.0;
	if (res < 0.0)
		res += 360.0;
	return (res);
}

t_hsl_color		rgb_to_hsl(int rgb, double c_max, double c_min)
{
	t_hsl_color	res;
	double		r_p;
	double		g_p;
	double		b_p;
	double		delta;

	r_p = (double)((rgb & 0xFF0000) >> 16) / 255.0;
	g_p = (double)((rgb & 0x00FF00) >> 8) / 255.0;
	b_p = (double)(rgb & 0x0000FF) / 255.0;
	c_max = ft_dmax(3, r_p, g_p, b_p);
	c_min = ft_dmin(3, r_p, g_p, b_p);
	delta = c_max - c_min;
	res.hue = hue(delta, r_p, g_p, b_p);
	res.light = (c_max + c_min) / 2.0;
	if (delta <= 0.0000001)
		res.saturation = 0.0;
	else
		res.saturation = delta / (1.0 - ft_fabs(2.0 * res.light - 1.0));
	return (res);
}
