/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:18:30 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/27 00:36:20 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_pressed(int keycode, int x, int y, void *param)
{
	t_frac *frac;

	frac = (t_frac*)param;
	if (keycode == 1 && frac->actual == FRAC_JULIA)
		frac->julia_move = !frac->julia_move;
	if (keycode == 4 && frac->zoom[FRAC] < MAX_ZOOM)
	{
		if (frac->zoom_at[FRAC])
		{
			frac->pt_view[FRAC] += ((double)(x - (WIN_WIDTH / 2)) /
				(WIN_WIDTH / 2)) * 0.2 / frac->zoom[FRAC];
			frac->pt_view[FRAC + 1] += ((double)(y - (WIN_HEIGHT / 2)) /
				(WIN_HEIGHT / 2)) * 0.2 / frac->zoom[FRAC];
		}
		frac->zoom[FRAC] *= 1 / 0.9;
		frac->max_iterations[FRAC] += 2;
	}
	if (keycode == 5)
	{
		if (frac->zoom_at[FRAC])
		{
			frac->pt_view[FRAC] += ((double)(x - (WIN_WIDTH / 2)) /
				(WIN_WIDTH / 2)) * 0.2 / frac->zoom[FRAC];
			frac->pt_view[FRAC + 1] += ((double)(y - (WIN_HEIGHT / 2)) /
				(WIN_HEIGHT / 2)) * 0.2 / frac->zoom[FRAC];
		}
		frac->zoom[FRAC] *= 0.9;
		frac->max_iterations[FRAC] -=
			(frac->max_iterations[FRAC] <= MIN_ITERATIONS) ? 0 : 2;
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
