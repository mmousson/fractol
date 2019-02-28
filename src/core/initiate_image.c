/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:07:42 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 06:11:52 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"

int	initiate_image(t_fractol *inf)
{
	int	bp;
	int	sl;
	int	end;

	if ((inf->img_v = mlx_new_image(inf->mlx, WIDTH, HEIGHT)) == NULL)
		return (0);
	if (!(inf->image = (int *)mlx_get_data_addr(inf->img_v, &bp, &sl, &end)))
		return (0);
	return (1);
}
