/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:32:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/27 16:30:22 by schaaban         ###   ########.fr       */
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
	{
		ft_putstr_fd("usage: fractol fractal_type ", 2);
		ft_putendl_fd("[mandle|julia|bship|mandle3] (win width)", 2);
	}
	ft_exit(frac);
}
