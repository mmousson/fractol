/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:20:01 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 11:18:02 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	ft_escape_handler(void *params, int keycode)
{
	t_fractol	*inf;

	(void)keycode;
	if (params == NULL)
		return ;
	inf = (t_fractol *)params;
	mlx_destroy_window(inf->mlx, inf->win);
	ft_memdel(&params);
	exit(0);
}
