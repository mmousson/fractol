/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clerp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:24:23 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 07:04:25 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_clerp(int color_a, int color_b, double t)
{
	int	r;
	int	g;
	int	b;
	int	color_result;

	r = (color_a & 0xFF0000) + (int)((double)(color_b & 0xFF0000) * t);
	g = (color_a & 0x00FF00) + (int)((double)(color_b & 0x00FF00) * t);
	b = (color_a & 0x0000FF) + (int)((double)(color_b & 0x0000FF) * t);
	color_result = r | g | b;
	return (color_result);
}
