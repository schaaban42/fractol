/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:32:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 17:56:29 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(t_frac *frac)
{
	frac = (t_frac*)frac;
	exit(0);
	return (0);
}

void	error_handler(int error, t_frac *frac)
{
	if (error == 0)
		ft_putendl_fd("usage: fractol fractal_type [mandle|julia|bship|mandle3]", 2);
	else if (error == 1)
		ft_putendl_fd("usage: fractol fractal_type [mandle|julia|bship|mandle3]", 2);
	ft_exit(frac);
}
