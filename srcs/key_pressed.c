/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:55:38 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 20:09:39 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keys.h"

static void	key_rgbmove(int keycode, t_frac *frac)
{
	if (keycode == KEY_T)
		frac->rgb[FRAC] += 1;
	if (keycode == KEY_G)
		frac->rgb[FRAC] -= (frac->rgb[FRAC] <= 0) ? 0 : 1;
	if (keycode == KEY_Y)
		frac->rgb[FRAC + 1] += 1;
	if (keycode == KEY_H)
		frac->rgb[FRAC + 1] -= (frac->rgb[FRAC + 1] <= 0) ? 0 : 1;
	if (keycode == KEY_U)
		frac->rgb[FRAC + 2] += 1;
	if (keycode == KEY_J)
		frac->rgb[FRAC + 2] -= (frac->rgb[FRAC + 2] <= 0) ? 0 : 1;
	if (keycode == KEY_LEFT)
		frac->pt_view[FRAC] -= 0.1 / frac->zoom[FRAC];
	if (keycode == KEY_RIGHT)
		frac->pt_view[FRAC] += 0.1 / frac->zoom[FRAC];
	if (keycode == KEY_UP)
		frac->pt_view[FRAC + 1] -= 0.1 / frac->zoom[FRAC];
	if (keycode == KEY_DOWN)
		frac->pt_view[FRAC + 1] += 0.1 / frac->zoom[FRAC];
}

int			key_pressed(int keycode, void *param)
{
	t_frac	*frac;

	frac = (t_frac*)param;
	if (keycode == KEY_ESC)
		ft_exit(frac);
	if (keycode == KEY_C)
		frac->actual += (frac->actual == 9) ? -9 : 3;
	if (keycode == KEY_PLUS)
		frac->max_iterations[FRAC] += 10;
	if (keycode == KEY_MINUS)
		frac->max_iterations[FRAC] -= (frac->max_iterations[FRAC] <= MIN_ITERATIONS) ? 0 : 10;
	if (keycode == KEY_R)
		init_frac(frac, FRAC);
	if (keycode == KEY_TAB)
		frac->ui = !frac->ui;
	if (keycode == KEY_Z)
		frac->zoom_at[FRAC] = !frac->zoom_at[FRAC];
	key_rgbmove(keycode, frac);
	draw_fractal(frac);
	return (0);
}
