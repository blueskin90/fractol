/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 01:54:37 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:56:15 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_multibrot(t_complex c, t_complex pow, int ite)
{
	int				i;
	float		retval;
	t_complex		z;

	z = ft_comp(0, 0);
	i = 1;
	z = ft_cadd(z, c);
	while (i < ite)
	{
		z = ft_cadd(ft_cpow(z, pow.r), c);
		if (ft_checkvalue(z) > 100)
		{
			retval = (i + 1 - log(log(ft_checkvalue(z))) / log(2)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
