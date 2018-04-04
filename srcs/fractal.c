/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:20:09 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/04 17:33:53 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_mandlebrot(int x, int y, t_frac *frac)
{
	double	c[FRAC_COUNT * 3];
	double	z[FRAC_COUNT * 3];
	double	tmp;
	int		i;

	c[FRAC] = (frac->pt_size[FRAC] * (x - WIN_WIDTH / 2) /
		(frac->zoom[FRAC] * WIN_WIDTH * 0.5)) + frac->pt_view[FRAC];
	c[FRAC + 1] = (frac->pt_size[FRAC + 1] * (y - WIN_HEIGHT / 2) /
		(frac->zoom[FRAC] * WIN_HEIGHT * -0.5)) - frac->pt_view[FRAC + 1];
	z[FRAC] = 0.0f;
	z[FRAC + 1] = 0.0f;
	i = 0;
	while (z[FRAC] * z[FRAC] + z[FRAC + 1] * z[FRAC + 1] < 4 &&
		++i < frac->max_iterations[FRAC])
	{
		tmp = z[FRAC];
		z[FRAC] = z[FRAC] * z[FRAC] - z[FRAC + 1] * z[FRAC + 1] + c[FRAC];
		z[FRAC + 1] = 2 * tmp * z[FRAC + 1] + c[FRAC + 1];
	}
	if (i < frac->max_iterations[FRAC])
		ft_put_pixel(x, y, ((i * frac->rgb[FRAC]) % 256) << 16 |
			((i * frac->rgb[FRAC + 1]) % 256) << 8 |
			((i * frac->rgb[FRAC + 2]) % 256) << 0, frac);
}

static void		draw_julia(int x, int y, t_frac *frac)
{
	double	c[FRAC_COUNT * 3];
	double	tmp;
	int		i;

	c[FRAC] = (frac->pt_size[FRAC] * (x - WIN_WIDTH / 2) /
		(frac->zoom[FRAC] * WIN_WIDTH * 0.5)) + frac->pt_view[FRAC];
	c[FRAC + 1] = (frac->pt_size[FRAC + 1] * (y - WIN_HEIGHT / 2) /
		(frac->zoom[FRAC] * WIN_HEIGHT * -0.5)) - frac->pt_view[FRAC + 1];
	i = 0;
	while (c[FRAC] * c[FRAC] + c[FRAC + 1] * c[FRAC + 1] < 4 &&
		++i < frac->max_iterations[FRAC])
	{
		tmp = c[FRAC];
		c[FRAC] = c[FRAC] * c[FRAC] -
			c[FRAC + 1] * c[FRAC + 1] + frac->julia[0];
		c[FRAC + 1] = 2 * tmp * c[FRAC + 1] + frac->julia[1];
	}
	if (i < frac->max_iterations[FRAC])
		ft_put_pixel(x, y, ((i * frac->rgb[FRAC]) % 256) << 16 |
			((i * frac->rgb[FRAC + 1]) % 256) << 8 |
			((i * frac->rgb[FRAC + 2]) % 256) << 0, frac);
}

static void		draw_burningship(int x, int y, t_frac *frac)
{
	double	c[FRAC_COUNT * 3];
	double	z[FRAC_COUNT * 3];
	double	tmp;
	int		i;

	c[FRAC] = (frac->pt_size[FRAC] * (x - WIN_WIDTH / 2) /
		(frac->zoom[FRAC] * WIN_WIDTH * 0.5)) + frac->pt_view[FRAC];
	c[FRAC + 1] = (frac->pt_size[FRAC + 1] * (y - WIN_HEIGHT / 2) /
		(frac->zoom[FRAC] * WIN_HEIGHT * 0.5)) + frac->pt_view[FRAC + 1];
	z[FRAC] = 0.0f;
	z[FRAC + 1] = 0.0f;
	i = 0;
	while (z[FRAC] * z[FRAC] + z[FRAC + 1] * z[FRAC + 1] < 4 &&
		++i < frac->max_iterations[FRAC])
	{
		tmp = z[FRAC];
		z[FRAC] = ft_abs(z[FRAC] * z[FRAC]) -
			ft_abs(z[FRAC + 1] * z[FRAC + 1]) + c[FRAC];
		z[FRAC + 1] = 2 * ft_abs(tmp) * ft_abs(z[FRAC + 1]) + c[FRAC + 1];
	}
	if (i < frac->max_iterations[FRAC])
		ft_put_pixel(x, y, ((i * frac->rgb[FRAC]) % 256) << 16 |
			((i * frac->rgb[FRAC + 1]) % 256) << 8 |
			((i * frac->rgb[FRAC + 2]) % 256) << 0, frac);
}

static void		draw_mandle3(int x, int y, t_frac *frac)
{
	double	c[FRAC_COUNT * 3];
	double	z[FRAC_COUNT * 3];
	double	tmp;
	int		i;

	c[FRAC] = (frac->pt_size[FRAC] * (x - WIN_WIDTH / 2) /
		(frac->zoom[FRAC] * WIN_WIDTH * 0.5)) + frac->pt_view[FRAC];
	c[FRAC + 1] = (frac->pt_size[FRAC + 1] * (y - WIN_HEIGHT / 2) /
		(frac->zoom[FRAC] * WIN_HEIGHT * 0.5)) + frac->pt_view[FRAC + 1];
	z[FRAC] = 0.0f;
	z[FRAC + 1] = 0.0f;
	i = 0;
	while (z[FRAC] * z[FRAC] + z[FRAC + 1] * z[FRAC + 1] < 4 &&
		++i < frac->max_iterations[FRAC])
	{
		tmp = z[FRAC];
		z[FRAC] = (z[FRAC] * z[FRAC] * z[FRAC]) -
			3 * (z[FRAC] * z[FRAC + 1] * z[FRAC + 1]) + c[FRAC];
		z[FRAC + 1] = 3 * (tmp * tmp) * (z[FRAC + 1]) -
			(z[FRAC + 1] * z[FRAC + 1] * z[FRAC + 1]) + c[FRAC + 1];
	}
	if (i < frac->max_iterations[FRAC])
		ft_put_pixel(x, y, ((i * frac->rgb[FRAC]) % 256) << 16 |
			((i * frac->rgb[FRAC + 1]) % 256) << 8 |
			((i * frac->rgb[FRAC + 2]) % 256) << 0, frac);
}

void			draw_fractal(t_frac *frac)
{
	int		i;
	int		j;

	i = -1;
	if (frac->zoom[FRAC] > MAX_ZOOM)
		frac->zoom[FRAC] = MAX_ZOOM;
	clear_win(0, frac);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			if (frac->actual == FRAC_MANDLE)
				draw_mandlebrot(j, i, frac);
			else if (frac->actual == FRAC_JULIA)
				draw_julia(j, i, frac);
			else if (frac->actual == FRAC_BSHIP)
				draw_burningship(j, i, frac);
			else if (frac->actual == FRAC_M3)
				draw_mandle3(j, i, frac);
		}
	}
	mlx_put_image_to_window(frac->mlx_core, frac->mlx_win, frac->mlx_img, 0, 0);
	draw_ui(frac);
}
