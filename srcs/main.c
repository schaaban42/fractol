/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:23:35 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/21 18:25:00 by schaaban         ###   ########.fr       */
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
	frac.pt_view[0] = -0.75;
	frac.pt_view[1] = 0.0;
	frac.pt_size[0] = 1.35;
	frac.pt_size[1] = 1.2;
	frac.rgb[0] = 5;
	frac.rgb[1] = 5;
	frac.rgb[2] = 5;
	frac.julia[0] = -0.5;
	frac.julia[1] = 0.5;
	frac.max_iterations = 100;
	frac.zoom = 1;
	frac.actual = FRAC_JULIA;
	frac.julia_move = 0;
	draw_fractal(&frac);
	mlx_put_image_to_window(frac.mlx_core, frac.mlx_win, frac.mlx_img, 0, 0);
	mlx_hook(frac.mlx_win, 2, 1L, key_pressed, (void*)&frac);
	mlx_mouse_hook(frac.mlx_win, mouse_pressed, (void*)&frac);
	mlx_hook(frac.mlx_win, 6, 1L<<6, mouse_moved, (void*)&frac);
	mlx_loop(frac.mlx_core);
	return (0);
}
