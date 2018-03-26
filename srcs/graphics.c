/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:10:24 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 19:40:08 by schaaban         ###   ########.fr       */
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
	j = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			frac->mlx_img_s[(i * WIN_WIDTH) + j] = color;
			j++;
		}
		i++;
	}
}
