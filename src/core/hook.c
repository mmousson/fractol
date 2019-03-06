/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 06:18:15 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/05 21:01:33 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"
#include "fractol_keys.h"

static float	dist(t_fractol *inf, int up_down)
{
	if (up_down)
		return (inf->limits.up - inf->limits.down);
	else
		return (inf->limits.left - inf->limits.right);
}

static void	zoom_in(void *params, int keycode)
{
	(void)keycode;
	((t_fractol *)params)->iterations_max++;
	((t_fractol *)params)->update(params);
}

static void	zoom_out(void *params, int keycode)
{
	(void)keycode;
	((t_fractol *)params)->iterations_max--;
	((t_fractol *)params)->update(params);
}

static void	move(void *params, int keycode)
{
	t_fractol	*inf;

	inf = (t_fractol *)params;
	if (keycode == UP && inf->limits.up > -1.2f)
	{
		inf->limits.up -= (0.1f) * (dist(inf, 1) / (1.2f - -1.2f));
		inf->limits.down -= (0.1f) * (dist(inf, 1) / (1.2f - -1.2f));
	}
	else if (keycode == DOWN && inf->limits.down < 1.2f)
	{
		inf->limits.up += (0.1f) * (dist(inf, 1) / (1.2f - -1.2f));
		inf->limits.down += (0.1f) * (dist(inf, 1) / (1.2f - -1.2f));
	}
	else if (keycode == LEFT && inf->limits.left > -2.1f)
	{
		inf->limits.left -= (0.1f) * (dist(inf, 0) / (0.6f - -2.1f));
		inf->limits.right -= (0.1f) * (dist(inf, 0) / (0.6f - -2.1f));
	}
	else if (keycode == RIGHT && inf->limits.right < 0.6f)
	{
		inf->limits.left += (0.1f) * (dist(inf, 0) / (0.6f - -2.1f));
		inf->limits.right += (0.1f) * (dist(inf, 0) / (0.6f - -2.1f));
	}
	((t_fractol *)params)->update(params);
}

int			key_manager(int keycode, void *params)
{
	const t_key_matcher			*ptr;
	static const t_key_matcher	dispatcher[8] = {
		{ESCAPE, &ft_escape_handler},
		{PLUS, &zoom_in},
		{MINUS, &zoom_out},
		{UP, &move}, {DOWN, &move}, {LEFT, &move}, {RIGHT, &move},
		{-1, NULL}
	};

	ptr = dispatcher;
	while (ptr->handler != NULL)
	{
		if (keycode == ptr->keycode)
		{
			ptr->handler(params, keycode);
			return (1);
		}
		ptr++;
	}
	printf("%d\n", keycode);
	return (0);
}
