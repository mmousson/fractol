/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_keys.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:14:37 by mmousson          #+#    #+#             */
/*   Updated: 2019/02/28 01:20:52 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_KEYS_H
# define FRACTOL_KEYS_H

# define ESCAPE 53
# define SPACE 49
# define RETURN 36
# define PLUS 69
# define MINUS 78
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

typedef struct	s_key_matcher
{
	int			keycode;
	void		(*handler) (void *params);
}				t_key_matcher;

void			ft_escape_handler(void *params);

#endif
