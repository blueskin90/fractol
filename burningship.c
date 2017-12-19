/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:21:08 by toliver           #+#    #+#             */
/*   Updated: 2017/12/15 22:43:09 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double			ft_burningship(t_complex c, t_complex z, int ite)
{
	int				i;
	long double		retval;

	i = 0;
	while (i < ite)
	{
		if (ft_checkvalue(z) > 100)
		{
			retval = (i + 1 - log(log(ft_checkvalue(z)))/log(2.0)) / ite;
			return (retval);
		}
		z = ft_cadd(ft_csqr(ft_cabs(z)), c);
		i++;
	}
	return (-1);
}
