/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:09:40 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 11:36:46 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_keys.h"
#include <stdlib.h>

int	key_manager(int keycode, void *params)
{
	const t_key_matcher			*ptr;
	static const t_key_matcher	dispatcher[2] = {
		{ESCAPE, &ft_escape_handler},
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
	return (0);
}
