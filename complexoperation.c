/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexoperation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:12:45 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:53:05 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_cmul(t_complex c1, t_complex c2)
{
	float		tmpr;
	float		tmpi;

	tmpr = c1.r;
	tmpi = c1.i;
	c1.r = c1.r * c2.r - c1.i * c2.i;
	c1.i = tmpr * c2.i + tmpi * c2.r;
	return (c1);
}

t_complex		ft_cadd(t_complex c1, t_complex c2)
{
	c1.r += c2.r;
	c1.i += c2.i;
	return (c1);
}

t_complex		ft_csqr(t_complex comp)
{
	float	tmp;

	tmp = comp.r;
	comp.r = comp.r * comp.r - comp.i * comp.i;
	comp.i = 2 * tmp * comp.i;
	return (comp);
}

t_complex		ft_cabs(t_complex c)
{
	c.r = fabs(c.r);
	c.i = fabs(c.i);
	return (c);
}

t_complex		ft_cpow(t_complex c, float power)
{
	float		tmp1;
	float		tmp2;
	float		tmp3;

	tmp1 = c.r * c.r + c.i * c.i;
	tmp1 = pow(tmp1, (float)power / 2);
	tmp2 = tmp1;
	tmp3 = power * atan2(c.i, c.r);
	tmp1 = tmp1 * cos(tmp3);
	tmp2 = tmp2 * sin(tmp3);
	return (ft_comp(tmp1, tmp2));
}
