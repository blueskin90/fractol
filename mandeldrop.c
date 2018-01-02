/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandeldrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 03:46:35 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:55:20 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_mandeldrop(t_complex c, t_complex z, int ite)
{
	int				i;
	float		retval;

	i = 0;
	c.r += c.i;
	c.i = c.r - c.i;
	c.r = c.r -= c.i;
	c = ft_cinv(c);
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			retval = (i + 1 - log(log(ft_checkvalue(z))) / log(2.0)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
