/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:27:17 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/12 14:46:22 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 854
# define WIN_TITLE "Fract'ol"

typedef struct	s_frac
{
	void	*mlx_core;
	void	*mlx_win;
	void	*mlx_img;
	int		*mlx_img_s;
	int		line_size;
	double	zoom;
	double	pt_view[2];
}				t_frac;

void			ft_put_pixel(int x, int y, int color, t_frac *frac);
int				color_gradient(int cs, int ce, double value);
void			clear_win(int color, t_frac *frac);

void			draw_fractal(t_frac *frac);

int				key_pressed(int keycode, void *param);

double			ft_step(double s, double e, double value);

void			ft_exit(t_frac *frac);
void			error_handler(int error, t_frac *frac);

#endif
