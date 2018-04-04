/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:18:28 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/04 16:34:49 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_frac(t_frac *frac, int f)
{
	int		i;

	i = f;
	if (f == FRAC_MANDLE)
		init_mandle(frac);
	else if (f == FRAC_JULIA)
		init_julia(frac);
	else if (f == FRAC_BSHIP)
		init_bship(frac);
	else if (f == FRAC_M3)
		init_m3(frac);
	while (i < f + 3)
		frac->rgb[i++] = 5;
}

void	ft_init(t_frac *frac, int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		error_handler(0, frac);
	if (ft_strequ(argv[1], "mandle"))
		frac->actual = FRAC_MANDLE;
	else if (ft_strequ(argv[1], "julia"))
		frac->actual = FRAC_JULIA;
	else if (ft_strequ(argv[1], "bship"))
		frac->actual = FRAC_BSHIP;
	else if (ft_strequ(argv[1], "mandle3"))
		frac->actual = FRAC_M3;
	else
		error_handler(0, frac);
	if (argc == 3)
	{
		if (!ft_str_isdigit(argv[2]))
			error_handler(0, frac);
		frac->win_width = (ft_atoi(argv[2]) > 80) ? ft_atoi(argv[2]) : 80;
		frac->win_width = (frac->win_width > 1200) ? 1200 : frac->win_width;
	}
	init_frac(frac, FRAC_MANDLE);
	init_frac(frac, FRAC_JULIA);
	init_frac(frac, FRAC_BSHIP);
	init_frac(frac, FRAC_M3);
	frac->julia_move = 1;
	frac->ui = 0;
}
