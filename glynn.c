/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:31:27 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:53:59 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_glynn(t_complex c, t_complex z, int ite)
{
	int				i;
	float		retval;

	z.r = -0.2;
	i = 0;
	c.r += c.i;
	c.i = c.r - c.i;
	c.r = c.r -= c.i;
	while (i < ite)
	{
		c = ft_cadd(ft_cpow(c, 1.5), z);
		if (ft_checkvalue(c) > 100)
		{
			retval = (i - log(log(ft_cmod(c)) / log(100)) / log(2)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
