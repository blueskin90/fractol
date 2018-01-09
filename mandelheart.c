/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelheart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 09:54:22 by toliver           #+#    #+#             */
/*   Updated: 2018/01/07 14:12:34 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float			ft_mandelheart(t_complex c, t_complex z, int ite)
{
	int			i;
	float		retval;

	i = -1;
	c.r += c.i;
	c.i = c.r - c.i;
	c.r = c.r -= c.i;
	c.r = (c.r >= 1) ? c.r * ((c.r - 1) / 5 + 1) : c.r;
	c.i = (c.r < 1.30) ? c.i / ((fabs(c.r - 1.30) / 3) / 2 + 1) : c.i;
	if (c.r < 0)
	{
		c.r = (c.r < -1) ? c.r * (1 - (c.r + 1)) : c.r;
		c.r = (fabs(c.i) < 0.5) ? c.r /= 1 - (fabs(fabs(c.i) - 0.5)) : c.r;
	}
	c = ft_cinv(c);
	while (++i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			retval = (i + 1 - log(log(ft_checkvalue(z))) / log(2.0)) / ite;
			return (retval);
		}
	}
	return (-1);
}
