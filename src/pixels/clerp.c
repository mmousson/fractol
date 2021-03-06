/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clerp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:24:23 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/06 00:45:43 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_clerp(int from, int to, double t)
{
	t_hsl_color	hsl_from;
	t_hsl_color	hsl_to;
	t_hsl_color	lerped;

	hsl_from = rgb_to_hsl(from, 0.0, 0.0);
	hsl_to = rgb_to_hsl(to, 0.0, 0.0);
	lerped.hue = (hsl_from.hue + hsl_to.hue) / t;
	lerped.saturation = (hsl_from.saturation + hsl_to.saturation) / t;
	lerped.light = (hsl_from.light + hsl_to.light) / t;
	return (hsl_to_rgb(lerped));
}
