/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:53:30 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 06:16:22 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 720
# define WIDTH 1080

# define BURNINGSHIP "burningship"
# define JULIA "julia"
# define MANDELBROT "mandelbrot"

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img_v;
	int			*image;
	char		*set;
	int			x;
	int			y;
	void		(*set_function) (struct s_fractol *inf);
}				t_fractol;

typedef struct	s_set_matcher
{
	char		*set_name;
	void		(*handler) (t_fractol *inf);
}				t_set_matcher;
void			ft_burningship(t_fractol *inf);
void			ft_julia(t_fractol *inf);
void			ft_mandelbrot(t_fractol *inf);

int				initiate_image(t_fractol *inf);
void			ft_put_pixel(int *image, int x, int y, int color);
int				select_set_function(char *set_name, t_fractol *inf);
int				key_manager(int keycode, void *params);

#endif
