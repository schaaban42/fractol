/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:10:24 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/12 14:34:44 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(int x, int y, int color, t_frac *frac)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		frac->mlx_img_s[(y * WIN_WIDTH) + x] = color;
}

int		color_gradient(int cs, int ce, double value)
{
	int		c1[3];
	int		c2[3];
	int		cf[3];

	c1[0] = cs & 0xFF0000;
	c1[1] = cs & 0x00FF00;
	c1[2] = cs & 0x0000FF;
	c2[0] = ce & 0xFF0000;
	c2[1] = ce & 0x00FF00;
	c2[2] = ce & 0x0000FF;
	cf[0] = (c1[0] + (int)((double)(c2[0] - c1[0]) * value)) & 0xFF0000;
	cf[1] = (c1[1] + (int)((double)(c2[1] - c1[1]) * value)) & 0x00FF00;
	cf[2] = (c1[2] + (int)((double)(c2[2] - c1[2]) * value)) & 0x0000FF;
	return (cf[0] | cf[1] | cf[2]);
}

void	clear_win(int color, t_frac *frac)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ft_put_pixel(j, i, color, frac);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(frac->mlx_core, frac->mlx_win, frac->mlx_img, 0, 0);
}
