/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:53:30 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 02:03:09 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1080
# define WIDTH 720

# define BURNINGSHIP "burningship"
# define JULIA "julia"
# define MANDELBROT "mandelbrot"

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*set;
	void		(*set_function) (void);
}				t_fractol;

void			ft_burningship(void);
void			ft_julia(void);
void			ft_mandelbrot(void);
typedef struct	s_set_matcher
{
	char		*set_name;
	void		(*handler) (void);
}				t_set_matcher;

int				select_set_function(char *set_name, t_fractol *inf);
int				key_manager(int keycode, void *params);

#endif
