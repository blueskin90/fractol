/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:29:20 by toliver           #+#    #+#             */
/*   Updated: 2018/01/07 21:02:43 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float			ft_julia(t_complex c, t_complex z, int ite)
{
	int			i;
	float		retval;

	i = 0;
	while (i < ite)
	{
		c = ft_cadd(ft_csqr(c), z);
		if (ft_checkvalue(c) > 512)
		{
			retval = (i - log(log(ft_cmod(c)) / log(100)) / log(2)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
