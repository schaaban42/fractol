/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:46:18 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 21:03:11 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_ui(t_frac *frac)
{
	if (!frac->ui)
		return ;
	if (FRAC == FRAC_MANDLE)
		ft_putendl("\n\n\n~ Mandlebrot ~");
	else if (FRAC == FRAC_JULIA)
		ft_putendl("\n\n\n~ Julia ~");
	else if (FRAC == FRAC_BSHIP)
		ft_putendl("\n\n\n~ Burning ship ~");
	else if (FRAC == FRAC_M3)
		ft_putendl("\n\n\n~ Mandlebrot ^ 3 ~");
	ft_printf("R : %d\nG : %d\nB : %d\nIterations : %d\n",
		frac->rgb[FRAC], frac->rgb[FRAC + 1], frac->rgb[FRAC + 2],
		frac->max_iterations[FRAC]);
	ft_printf("Follow cursor : %d\n", frac->zoom_at[FRAC]);
}
