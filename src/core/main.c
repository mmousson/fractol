/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:23:34 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/02 06:15:07 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"

static int	ft_usage(void)
{
	ft_putendl_fd("usage: fractol [julia][mandelbrot][burningship]", 2);
	return (1);
}

static int	ft_bootup(char *set)
{
	t_fractol	*inf;

	if ((inf = (t_fractol *)ft_memalloc(sizeof(t_fractol))) == NULL)
	{
		ft_putendl_fd("Internal malloc error", 2);
		return (0);
	}
	inf->set = set;
	if ((inf->mlx = mlx_init()) == NULL
		|| (inf->win = mlx_new_window(inf->mlx, WIDTH, HEIGHT, set)) == NULL
		|| initiate_image(inf) == 0
		|| select_set_function(set, inf) == 0)
	{
		ft_putendl_fd("Failed to connect to graphic interface", 2);
		return (0);
	}
	mlx_clear_window(inf->mlx, inf->win);
	ft_bzero(inf->image, WIDTH * HEIGHT * 4);
	inf->set_function(inf);
	return (1);
}

int			main(int argc, char **argv)
{
	argc--;
	argv++;
	if (argc == 1 && (ft_strequ(argv[0], JULIA)
		|| ft_strequ(argv[0], MANDELBROT)
		|| ft_strequ(argv[0], BURNINGSHIP)))
	{
		if (ft_bootup(argv[0]) == 0)
			return (1);
	}
	else
		return (ft_usage());
	return (0);
}

