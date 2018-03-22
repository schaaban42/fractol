/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:20:09 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/21 18:34:06 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_mandlebrot(int x, int y, t_frac *frac)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;

	c[0] = (frac->pt_size[0] * (x - WIN_WIDTH / 2) / 
		(frac->zoom * WIN_WIDTH * 0.5)) + frac->pt_view[0];
	c[1] = (frac->pt_size[1] * (y - WIN_HEIGHT / 2) / 
		(frac->zoom * WIN_HEIGHT * 0.5)) + frac->pt_view[1];
	z[0] = 0.0f;
	z[1] = 0.0f;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && ++i < frac->max_iterations)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * tmp * z[1] + c[1];
	}
	if (i < frac->max_iterations)
		ft_put_pixel(x, y, 
			(i * frac->rgb[0] % 256) << 16 | 
			(i * frac->rgb[1] % 256) << 8 | 
			(i * frac->rgb[2] % 256) << 0, frac);
}

static void		draw_julia(int x, int y, t_frac *frac)
{
	double	c[2];
	double	tmp;
	int		i;

	c[0] = (frac->pt_size[0] * (x - WIN_WIDTH / 2) / 
		(frac->zoom * WIN_WIDTH * 0.5)) + frac->pt_view[0];
	c[1] = (frac->pt_size[1] * (y - WIN_HEIGHT / 2) / 
		(frac->zoom * WIN_HEIGHT * 0.5)) + frac->pt_view[1];
	i = 0;
	while (c[0] * c[0] + c[1] * c[1] < 4 && ++i < frac->max_iterations)
	{
		tmp = c[0];
		c[0] = c[0] * c[0] - c[1] * c[1] + frac->julia[0];
		c[1] = 2 * tmp * c[1] + frac->julia[1];
	}
	if (i < frac->max_iterations)
		ft_put_pixel(x, y, 
			(i * frac->rgb[0] % 256) << 16 | 
			(i * frac->rgb[1] % 256) << 8 | 
			(i * frac->rgb[2] % 256) << 0, frac);
}

void			draw_fractal(t_frac *frac)
{
	int		i;
	int		j;

	i = 0;
	clear_win(0, frac);
	printf("z:%f\n", frac->zoom);
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (frac->actual == FRAC_MANDLE)
				draw_mandlebrot(j, i, frac);
			else if (frac->actual == FRAC_JULIA)
				draw_julia(j, i, frac);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(frac->mlx_core, frac->mlx_win, frac->mlx_img, 0, 0);
}
