/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:14:54 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/06 01:37:24 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_press(int button, int x, int y, void *params)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		if (((t_fractol *)params)->limits.right >= -0.000001f)
			return (1);
		((t_fractol *)params)->limits.up /= 1.1f;
		((t_fractol *)params)->limits.down /= 1.1f;
		((t_fractol *)params)->limits.left /= 1.1f;
		((t_fractol *)params)->limits.right /= 1.1f;
	}
	else if (button == 5)
	{
		((t_fractol *)params)->limits.up *= 1.1f;
		((t_fractol *)params)->limits.down *= 1.1f;
		((t_fractol *)params)->limits.left *= 1.1f;
		((t_fractol *)params)->limits.right *= 1.1f;
	}
	((t_fractol *)params)->update(params);
	return (1);
}

int			mouse_move(int x, int y, void *params)
{
	double		width;
	double		height;
	t_fractol	*inf;

	width = (double)x;
	height = (double)y;
	inf = (t_fractol *)params;
	inf->params.c_r = width / WIDTH;
	inf->params.c_i = height / HEIGHT;
	((t_fractol *)params)->update(params);
	return (1);
}
