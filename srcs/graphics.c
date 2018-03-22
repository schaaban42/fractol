/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:10:24 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/21 00:07:41 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(int x, int y, int color, t_frac *frac)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		frac->mlx_img_s[(y * WIN_WIDTH) + x] = color;
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
