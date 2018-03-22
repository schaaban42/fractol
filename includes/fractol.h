/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:27:17 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/21 18:24:45 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define WIN_WIDTH		500
# define WIN_HEIGHT		(int)(WIN_WIDTH * 0.8888888888)
# define WIN_TITLE		"Fract'ol"

# define FRAC_MANDLE	0
# define FRAC_JULIA		2

typedef struct	s_frac
{
	void	*mlx_core;
	void	*mlx_win;
	void	*mlx_img;
	int		*mlx_img_s;
	int		line_size;
	int		actual;
	int		max_iterations;
	int		julia_move;
	int		rgb[3];
	double	zoom;
	double	pt_view[2];
	double	pt_size[2];
	double	julia[2];
}				t_frac;

void			ft_put_pixel(int x, int y, int color, t_frac *frac);
void			clear_win(int color, t_frac *frac);

void			draw_fractal(t_frac *frac);

int				key_pressed(int keycode, void *param);

int				mouse_pressed(int keycode, int x, int y, void *param);
int				mouse_moved(int x, int y, void *param);

double			ft_step(double s, double e, double value);

void			ft_exit(t_frac *frac);
void			error_handler(int error, t_frac *frac);

#endif
