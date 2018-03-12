/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:20:09 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/12 14:44:32 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_pixel(int x, int y, t_frac *frac)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	int		i;
	int		max_iterations;

	cr = ft_step(-2, 1, ((double)x / (double)WIN_WIDTH));
	ci = ft_step(-1, 1, ((double)y / (double)WIN_HEIGHT));
	zr = 0.0f;
	zi = 0.0f;
	i = 0;
	max_iterations = 500;
	while (zr * zr + zi * zi < 4 && ++i < max_iterations)
	{
		double tmp;
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
	}
	if (i < max_iterations)
	{
		int color = 0;
		int c1 = 0xff0000, c2 = 0x0000ff;
		color = color_gradient(c1, c2, ((double)i / (double)max_iterations) * 5);
		ft_put_pixel(x, y, color, frac);
	}
}

void			draw_fractal(t_frac *frac)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			draw_pixel(j, i, frac);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(frac->mlx_core, frac->mlx_win, frac->mlx_img, 0, 0);
}
