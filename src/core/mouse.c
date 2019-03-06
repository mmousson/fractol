/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:14:54 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/05 20:58:14 by mmousson         ###   ########.fr       */
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
