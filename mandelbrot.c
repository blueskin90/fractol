/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:13:22 by toliver           #+#    #+#             */
/*   Updated: 2018/01/07 21:02:54 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float				ft_checkvalue(t_complex comp)
{
	return (comp.r * comp.r + comp.i * comp.i);
}

float				ft_mandelbrot(t_complex c, t_complex z, int ite)
{
	int				i;
	float			retval;

	i = 0;
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			retval = (i + 1 - log(log(ft_checkvalue(z))) / log(2)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
