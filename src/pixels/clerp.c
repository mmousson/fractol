/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clerp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:24:23 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 00:22:07 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_clerp(int from, int to, double t)
{
	int	r;
	int	g;
	int	b;
	int	color_result;

	r = (((from & 0xFF0000) >> 16)
		+ (((to & 0xFF0000) >> 16) - ((from & 0xFF0000) >> 16)) * t);
	r = r << 16;
	g = (((from & 0x00FF00) >> 8)
		+ (((to & 0x00FF00) >> 8) - ((from & 0x00FF00) >> 8)) * t);
	g = g << 8;
	b = ((from & 0x0000FF)) + ((to & 0x0000FF) - (from & 0x0000FF)) * t;
	// r = (from & 0xFF0000) + ((double)((to & 0xFF0000) - (from & 0xFF0000))) * t;
	// g = (from & 0x00FF00) + ((double)((to & 0x00FF00) - (from & 0x00FF00))) * t;
	// b = (from & 0x0000FF) + ((double)((to & 0x0000FF) - (from & 0x0000FF))) * t;
	color_result = r | g | b;
	return (color_result);
}
