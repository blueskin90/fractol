/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:18:13 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:52:50 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_comp(float x, float y)
{
	t_complex	comp;

	comp.r = x;
	comp.i = y;
	return (comp);
}

float			ft_cmod(t_complex comp)
{
	return (sqrt(comp.r * comp.r + comp.i * comp.i));
}

float			ft_cangle(t_complex c)
{
	float		angle;

	angle = atan(c.i / c.r);
	return (angle);
}

t_complex		ft_conj(t_complex c)
{
	c.i = -c.i;
	return (c);
}

t_complex		ft_cinv(t_complex c)
{
	float		div;

	div = c.r * c.r + c.i * c.i;
	c.r = c.r / div;
	c.i = -c.i / div;
	return (c);
}
