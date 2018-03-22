/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:55:38 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/21 18:31:30 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keys.h"

int			key_pressed(int keycode, void *param)
{
	t_frac	*frac;

	frac = (t_frac*)param;
	if (keycode == KEYS_ESC)
		ft_exit(frac);
	if (keycode == KEYS_C)
	{
		if (frac->actual == FRAC_JULIA)
			frac->actual = FRAC_MANDLE;
		else if (frac->actual == FRAC_MANDLE)
			frac->actual = FRAC_JULIA;
	}
	if (keycode == KEYS_ADD)
	{
		frac->max_iterations += 10;
	}
	if (keycode == KEYS_MINUS)
	{
		frac->max_iterations -= (frac->max_iterations <= 30) ? 0 : 10;
	}
	if (keycode == KEYS_R)
		frac->rgb[0] += 1;
	if (keycode == KEYS_F)
		frac->rgb[0] -= (frac->rgb[0] <= 0) ? 0 : 1;
	if (keycode == KEYS_T)
		frac->rgb[1] += 1;
	if (keycode == KEYS_G)
		frac->rgb[1] -= (frac->rgb[1] <= 0) ? 0 : 1;
	if (keycode == KEYS_Y)
		frac->rgb[2] += 1;
	if (keycode == KEYS_H)
		frac->rgb[2] -= (frac->rgb[2] <= 0) ? 0 : 1;
	if (keycode == KEYS_LEFT)
		frac->pt_view[0] -= 0.1 / frac->zoom;
	if (keycode == KEYS_RIGHT)
		frac->pt_view[0] += 0.1 / frac->zoom;
	if (keycode == KEYS_UP)
		frac->pt_view[1] -= 0.1 / frac->zoom;
	if (keycode == KEYS_DOWN)
		frac->pt_view[1] += 0.1 / frac->zoom;
	draw_fractal(frac);
	frac = (t_frac*)frac;
	return (0);
}
