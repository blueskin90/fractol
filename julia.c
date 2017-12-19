/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:29:20 by toliver           #+#    #+#             */
/*   Updated: 2017/12/15 23:07:04 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double				ft_julia(t_complex c, t_complex z, int ite)
{
	int				i;
	long double		retval;

	i = 0;
	while (i < ite)
	{
		c = ft_cadd(ft_csqr(c), z);
		if (ft_checkvalue(c) > 100)
		{
			retval = (i - log(log(ft_cmod(c)) / log(100)) / log(2)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
