/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:53:30 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/06 00:52:15 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1080
# define WIDTH 1080

# define BURNINGSHIP "burningship"
# define JULIA "julia"
# define MANDELBROT "mandelbrot"

typedef struct	s_limits
{
	double		up;
	double		down;
	double		left;
	double		right;
}				t_limits;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img_v;
	int			*image;
	char		*set;
	int			x;
	int			y;
	int			iterations_max;
	t_limits	limits;
	void		(*set_function) (struct s_fractol *inf);
	void		(*update) (void *params);
}				t_fractol;

typedef struct	s_hsl_color
{
	double		hue;
	double		saturation;
	double		light;
}				t_hsl_color;

typedef struct	s_set_matcher
{
	char		*set_name;
	void		(*handler) (t_fractol *inf);
}				t_set_matcher;

void			ft_burningship(t_fractol *inf);
void			ft_julia(t_fractol *inf);
void			ft_mandelbrot(t_fractol *inf);
void			burningship_generate(void *params);
void			mandelbrot_generate(void *params);

int				initiate_image(t_fractol *inf);
void			ft_put_pixel(int *image, int x, int y, int color);
int				ft_clerp(int color_a, int color_b, double t);
t_hsl_color		rgb_to_hsl(int rgb, double c_max, double c_min);
int				hsl_to_rgb(t_hsl_color hsl);
int				fractol_gradient(t_fractol *inf, double delta);
int				select_set_function(char *set_name, t_fractol *inf);
int				key_manager(int keycode, void *params);
int				mouse_press(int button, int x, int y, void *params);

#endif
