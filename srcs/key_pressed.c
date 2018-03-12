/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:55:38 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/12 12:19:59 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_pressed(int keycode, void *param)
{
	t_frac	*frac;

	frac = (t_frac*)param;
	ft_printf("%d\n", keycode);
	if (keycode == 24)
		frac->zoom += 0.2;
	clear_win(0, frac);
	draw_fractal(frac);
	if (keycode == 53)
		ft_exit(frac);
	frac = (t_frac*)frac;
	return (0);
}
