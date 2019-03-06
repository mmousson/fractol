/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:52:05 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/06 00:27:30 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fractol.h"

static int	merge(double c, double x, double m, double hue)
{
	if (hue <= 60.0)
		return ((int)((c + m) * 255) << 16 | (int)((x + m) * 255) << 8
			| (int)(m * 255));
	else if (hue <= 120.0)
		return ((int)((x + m) * 255) << 16 | (int)((c + m) * 255) << 8
			| (int)(m * 255));
	else if (hue <= 180.0)
		return ((int)(m * 255) << 16 | (int)((c + m) * 255) << 8
			| (int)((x + m) * 255));
	else if (hue <= 240.0)
		return ((int)(m * 255) << 16 | (int)((x + m) * 255) << 8
			| (int)((c + m) * 255));
	else if (hue <= 300.0)
		return ((int)((x + m) * 255) << 16 | (int)(m * 255) << 8
			| (int)((c + m) * 255));
	else
		return ((int)((c + m) * 255) << 16 | (int)(m * 255) << 8
			| (int)((x + m) * 255));
}

int			hsl_to_rgb(t_hsl_color hsl)
{
	double	c;
	double	x;
	double	m;

	c = (1.0 - ft_fabs(2.0 * hsl.light - 1.0)) * hsl.saturation;
	x = c * (1.0 - ft_fabs((double)((int)(hsl.hue / 60.0) % 2) - 1.0));
	m = hsl.light - (c / 2.0);
	return (merge(c, x, m, hsl.hue));
}
