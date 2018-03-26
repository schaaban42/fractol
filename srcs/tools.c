/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:33:16 by schaaban          #+#    #+#             */
/*   Updated: 2018/03/26 10:46:52 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_abs(double n)
{
	return ((n < 0) ? -n : n);
}

double		ft_step(double s, double e, double value)
{
	return ((double)(s + ((e - s) * value)));
}
