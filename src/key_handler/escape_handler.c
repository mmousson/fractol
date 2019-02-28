/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:20:01 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 01:41:27 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"

void	ft_escape_handler(void *params)
{
	t_fractol	*inf;

	if (params == NULL)
		return ;
	inf = (t_fractol *)params;
	mlx_destroy_window(inf->mlx, inf->win);
	exit(0);
}
