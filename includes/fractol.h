/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:27:17 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/04 16:24:53 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define WIN_RATIO		(double)0.888888889
# define WIN_WIDTH		frac->win_width
# define WIN_HEIGHT		(int)(WIN_WIDTH * WIN_RATIO)
# define WIN_TITLE		"Fract'ol"

# define FRAC			frac->actual
# define FRAC_COUNT		4
# define FRAC_MANDLE	0
# define FRAC_JULIA		3
# define FRAC_BSHIP		6
# define FRAC_M3		9

# define MIN_ITERATIONS	30
# define MAX_ZOOM		(double)100000000000000.0

typedef struct	s_frac
{
	void	*mlx_core;
	void	*mlx_win;
	void	*mlx_img;
	int		*mlx_img_s;
	int		line_size;
	int		actual;
	int		max_iterations[FRAC_COUNT * 3];
	int		julia_move;
	int		ui;
	int		zoom_at[FRAC_COUNT * 3];
	int		rgb[FRAC_COUNT * 3];
	int		win_width;
	double	zoom[FRAC_COUNT * 3];
	double	pt_view[FRAC_COUNT * 3];
	double	pt_size[FRAC_COUNT * 3];
	double	julia[2];
}				t_frac;

void			init_frac(t_frac *frac, int f);
void			ft_init(t_frac *frac, int argc, char **argv);

void			init_julia(t_frac *frac);
void			init_mandle(t_frac *frac);
void			init_bship(t_frac *frac);
void			init_m3(t_frac *frac);

void			ft_put_pixel(int x, int y, int color, t_frac *frac);
void			clear_win(int color, t_frac *frac);

void			draw_fractal(t_frac *frac);

int				key_pressed(int keycode, void *param);

int				mouse_pressed(int keycode, int x, int y, void *param);
int				mouse_moved(int x, int y, void *param);

void			draw_ui(t_frac *frac);

double			ft_abs(double n);
double			ft_step(double s, double e, double value);

int				ft_exit(t_frac *frac);
void			error_handler(int error, t_frac *frac);

#endif
