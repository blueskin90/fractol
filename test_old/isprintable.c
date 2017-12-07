/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprintable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 08:35:35 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:46:46 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			in_range(double to_check, int wintocheck)
{
	return ((to_check >= 0 && to_check < wintocheck) ? 1 : 0);
}

int			aux_lkot_primen(double cd, double oalo, int winx, int winy)
{
	return ((in_range(oalo, winy)
			|| in_range(oalo + (winy * cd), winy)
			|| in_range(-oalo / cd, winx)
			|| in_range((winx - oalo) / cd, winy)) ? 1 : -1);
}

int			leo_kot_prime_numbers(t_vector4 a, t_vector4 b, int winx, int winy)
{
	double	dx;
	double	cd;
	double	oalo;

	dx = b.x - a.x;
	if (!dx)
		return (-1);
	cd = (double)(b.y - a.y) / dx;
	if (!cd)
		return (-1);
	oalo = a.y - (a.x * cd);
	return (aux_lkot_primen(cd, oalo, winx, winy));
}

int			whichside(t_vector4 a, int winx, int winy)
{
	if (a.x < 0)
	{
		if (a.y < 0)
			return (35);
		if (a.y >= winy)
			return (91);
		return (7);
	}
	if (a.x >= winx)
	{
		if (a.y < 0)
			return (55);
		if (a.y >= winy)
			return (141);
		return (11);
	}
	if (a.y < 0)
		return (5);
	if (a.y >= winy)
		return (13);
	return (0);
}

int			isprintable(t_vector4 a, t_vector4 b, t_data *data)
{
	int		sidea;
	int		sideb;
	int		ssum;

	sidea = whichside(a, data->winx, data->winy);
	sideb = whichside(b, data->winx, data->winy);
	if (!sidea || !sideb)
	{
		if (sidea == sideb)
			return (0);
		return (1);
	}
	if (sidea + sideb == 18)
		return (1);
	ssum = sidea + sideb;
	if (ssum % 5 == 0 || ssum % 7 == 0 || ssum % 11 == 0 || ssum % 13 == 0)
		return (-1);
	return (leo_kot_prime_numbers(a, b, data->winx, data->winy));
}
