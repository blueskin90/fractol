/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:19:24 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 01:32:35 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_triangle	ft_uppertri(t_triangle tri)
{
	tri.b.x = (tri.a.x - tri.b.x) / 2 + tri.b.x;
	tri.b.y = (tri.b.y - tri.a.y) / 2 + tri.a.y;
	tri.c.x = (tri.c.x - tri.a.x) / 2 + tri.a.x;
	tri.c.y = (tri.c.y - tri.a.y) / 2 + tri.a.y;
	return (tri);
}

t_triangle	ft_lefttri(t_triangle tri)
{
	tri.c.x = tri.a.x;
	tri.a.x = (tri.a.x - tri.b.x) / 2 + tri.b.x;
	tri.a.y = (tri.b.y - tri.a.y) / 2 + tri.a.y;
	return (tri);
}

t_triangle	ft_righttri(t_triangle tri)
{
	tri.b.x = tri.a.x;
	tri.a.x = (tri.c.x - tri.a.x) / 2 + tri.a.x;
	tri.a.y = (tri.c.y - tri.a.y) / 2 + tri.a.y;
	return (tri);
}

void		ft_sierpinsky(t_triangle tri, t_data *data, int i)
{
	if (i > 8)
		i = 8;
	if (i == 0)
		ft_triangle(tri, data);
	else
	{
		ft_sierpinsky(ft_uppertri(tri), data, i - 1);
		ft_sierpinsky(ft_lefttri(tri), data, i - 1);
		ft_sierpinsky(ft_righttri(tri), data, i - 1);
	}
}

void		ft_triangle(t_triangle tri, t_data *data)
{
	ft_line(tri.a, tri.b, data);
	ft_line(tri.b, tri.c, data);
	ft_line(tri.c, tri.a, data);
}
