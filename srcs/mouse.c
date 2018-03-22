/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:18:30 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/21 18:25:27 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_pressed(int keycode, int x, int y, void *param)
{
	t_frac *frac;

	frac = (t_frac*)param;
	x = y;
	y = x;
	printf("%d\n", keycode);
	if (keycode == 1)
		frac->julia_move = !frac->julia_move;
	if (keycode == 4)
	{
		frac->zoom *= 1 / 0.9;
		frac->max_iterations += 1;
	}
	if (keycode == 5)
	{
		frac->zoom *= 0.9;
		frac->max_iterations -= (frac->max_iterations <= 30) ? 0 : 1;
	}
	draw_fractal(frac);
	return (0);
}

int		mouse_moved(int x, int y, void *param)
{
	t_frac	*frac;

	frac = (t_frac*)param;
	if (frac->actual == FRAC_JULIA && frac->julia_move)
	{
		frac->julia[0] = ft_step(-1, 1, (double)x / WIN_WIDTH);
		frac->julia[1] = ft_step(-1, 1, (double)y / WIN_HEIGHT);
		draw_fractal(frac);
	}
	return (0);
}
