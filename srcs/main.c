/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:23:35 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 17:45:25 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_frac	frac;
	int		a, b;

	ft_init(&frac, argc, argv);
	frac.mlx_core = mlx_init();
	frac.mlx_win = mlx_new_window(frac.mlx_core, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	frac.mlx_img = mlx_new_image(frac.mlx_core, WIN_WIDTH, WIN_HEIGHT);
	frac.mlx_img_s = (int*)mlx_get_data_addr(frac.mlx_img, &a, &frac.line_size, &b);
	draw_fractal(&frac);
	mlx_hook(frac.mlx_win, 2, 1L, key_pressed, (void*)&frac);
	mlx_mouse_hook(frac.mlx_win, mouse_pressed, (void*)&frac);
	mlx_hook(frac.mlx_win, 6, 1L<<6, mouse_moved, (void*)&frac);
	mlx_hook(frac.mlx_win, 17, 0, ft_exit, (void*)&frac);
	mlx_loop(frac.mlx_core);
	return (0);
}
