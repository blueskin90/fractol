/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 01:11:36 by toliver           #+#    #+#             */
/*   Updated: 2017/12/04 10:53:41 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			xmoving(t_parsedmap *map, int x)
{
	size_t	i;

	i = -1;
	while (++i < map->array_size)
		map->point[i].x -= x;
	return (1);
}

int			ymoving(t_parsedmap *map, int y)
{
	size_t	i;

	i = -1;
	while (++i < map->array_size)
		map->point[i].y -= y;
	return (1);
}
