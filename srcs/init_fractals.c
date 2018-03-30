/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:46:41 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/29 14:49:45 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_frac *frac)
{
	frac->pt_view[FRAC_JULIA + 0] = 0.0;
	frac->pt_view[FRAC_JULIA + 1] = 0.0;
	frac->pt_size[FRAC_JULIA + 0] = (1.0 / WIN_RATIO);
	frac->pt_size[FRAC_JULIA + 1] = 1;
	frac->zoom[FRAC_JULIA] = 0.6;
	frac->max_iterations[FRAC_JULIA] = 80;
	frac->julia[0] = -0.7698;
	frac->julia[1] = 0.2889;
	frac->julia_move = 0;
	frac->zoom_at[FRAC_JULIA] = 1;
}

void	init_mandle(t_frac *frac)
{
	frac->pt_view[FRAC_MANDLE + 0] = -0.75;
	frac->pt_view[FRAC_MANDLE + 1] = 0.0;
	frac->pt_size[FRAC_MANDLE + 0] = 1.35;
	frac->pt_size[FRAC_MANDLE + 1] = 1.2;
	frac->zoom[FRAC_MANDLE] = 1;
	frac->max_iterations[FRAC_MANDLE] = 100;
	frac->zoom_at[FRAC_MANDLE] = 1;
}

void	init_bship(t_frac *frac)
{
	frac->pt_view[FRAC_BSHIP + 0] = -0.40;
	frac->pt_view[FRAC_BSHIP + 1] = -0.50;
	frac->pt_size[FRAC_BSHIP + 0] = WIN_RATIO;
	frac->pt_size[FRAC_BSHIP + 1] = 1;
	frac->zoom[FRAC_BSHIP] = 0.5;
	frac->max_iterations[FRAC_BSHIP] = 50;
	frac->zoom_at[FRAC_BSHIP] = 1;
}

void	init_m3(t_frac *frac)
{
	frac->pt_view[FRAC_M3 + 0] = 0.0;
	frac->pt_view[FRAC_M3 + 1] = 0.0;
	frac->pt_size[FRAC_M3 + 0] = 1.35;
	frac->pt_size[FRAC_M3 + 1] = 1.2;
	frac->zoom[FRAC_M3] = 0.85;
	frac->max_iterations[FRAC_M3] = 100;
	frac->zoom_at[FRAC_M3] = 1;
}
