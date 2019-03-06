/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:02:57 by marvin            #+#    #+#             */
/*   Updated: 2019/03/05 16:02:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_fabs(double x)
{
	union				result
	{
		double			double_corres;
		unsigned long	int_corres;
	}					matcher;
	
	matcher.double_corres = x;
	matcher.int_corres &= ~(1UL << 63);
	return (matcher.double_corres);
}
