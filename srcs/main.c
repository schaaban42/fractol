/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:23:35 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/12 12:44:41 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_frac	frac;
	int		a, b;

	frac.mlx_core = mlx_init();
	frac.mlx_win = mlx_new_window(frac.mlx_core, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	frac.mlx_img = mlx_new_image(frac.mlx_core, WIN_WIDTH, WIN_HEIGHT);
	frac.mlx_img_s = (int*)mlx_get_data_addr(frac.mlx_img, &a, &frac.line_size, &b);
	clear_win(0, &frac);
	frac.zoom = 0.3;
	draw_fractal(&frac);
	mlx_put_image_to_window(frac.mlx_core, frac.mlx_win, frac.mlx_img, 0, 0);
	mlx_hook(frac.mlx_win, 2, 1L, key_pressed, (void*)&frac);
	mlx_loop(frac.mlx_core);
	return (0);
}
