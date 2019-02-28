/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_set_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:52:49 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 02:03:26 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "libft.h"

int	select_set_function(char *set_name, t_fractol *inf)
{
	const t_set_matcher			*ptr;
	static const t_set_matcher	dispatcher[4] = {
		{BURNINGSHIP, &ft_burningship},
		{JULIA, &ft_julia},
		{MANDELBROT, &ft_mandelbrot},
		{NULL, NULL}
	};

	ptr = dispatcher;
	while (ptr->set_name != NULL)
	{
		if (ft_strequ(set_name, ptr->set_name))
		{
			inf->set_function = ptr->handler;
			return (1);
		}
	}
	return (0);
}
