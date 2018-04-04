/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:18:30 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/04 17:39:12 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mouse_zoom_in(int x, int y, t_frac *frac)
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

static void		mouse_zoom_out(int x, int y, t_frac *frac)
{
	if (frac->zoom_at[FRAC])
	{
		frac->pt_view[FRAC] += ((double)(x - (WIN_WIDTH / 2)) /
			(WIN_WIDTH / 2)) * 0.2 / frac->zoom[FRAC];
		frac->pt_view[FRAC + 1] += ((double)(y - (WIN_HEIGHT / 2)) /
			(WIN_HEIGHT / 2)) * 0.2 / frac->zoom[FRAC];
	}
	frac->zoom[FRAC] *= 0.9;
	frac->max_iterations[FRAC] =
		(frac->max_iterations[FRAC] - 2 < MIN_ITERATIONS) ?
			MIN_ITERATIONS : (frac->max_iterations[FRAC] - 2);
}

int				mouse_pressed(int keycode, int x, int y, void *param)
{
	t_frac *frac;

	frac = (t_frac*)param;
	if (keycode == 1 && frac->actual == FRAC_JULIA)
		frac->julia_move = !frac->julia_move;
	if (keycode == 4 && frac->zoom[FRAC] < MAX_ZOOM)
		mouse_zoom_in(x, y, frac);
	if (keycode == 5)
		mouse_zoom_out(x, y, frac);
	draw_fractal(frac);
	return (0);
}

int				mouse_moved(int x, int y, void *param)
{
	t_frac	*frac;

	frac = (t_frac*)param;
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return (0);
	if (frac->actual == FRAC_JULIA && frac->julia_move)
	{
		frac->julia[0] = ft_step(-1, 1, (double)x / WIN_WIDTH);
		frac->julia[1] = ft_step(-1, 1, (double)y / WIN_HEIGHT);
		draw_fractal(frac);
	}
	return (0);
}
