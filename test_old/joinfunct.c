/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:56:26 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 17:59:06 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			jointoprec(size_t i, t_vector4 *vector, t_data *data)
{
	if (i > 0 && i % data->map->array_size != 0 &&
			isprintable(vector[i], vector[i - 1], data) >= 0)
	{
		if (isprintable(vector[i], vector[i - 1], data) == 0)
			putline(vector[i], vector[i - 1], data);
		else
			putlinepart(vector[i], vector[i - 1], data);
	}
}

void			jointoupper(size_t i, t_vector4 *vector, t_data *data)
{
	if (i >= data->map->array_size &&
			isprintable(vector[i], vector[i - data->map->array_size], data)
			>= 0)
	{
		if (!(isprintable(vector[i], vector[i - data->map->array_size], data)))
			putline(vector[i], vector[i - data->map->array_size], data);
		else
			putlinepart(vector[i], vector[i - data->map->array_size], data);
	}
}

void			jointodiag(size_t i, t_vector4 *vector, t_data *data)
{
	if (i > data->map->array_size && i % data->map->array_size != 0 &&
			isprintable(vector[i], vector[i - data->map->array_size - 1], data)
			>= 0)
	{
		if (isprintable(vector[i], vector[i - data->map->array_size - 1], data)
			== 0)
			putline(vector[i], vector[i - data->map->array_size - 1], data);
		else
			putlinepart(vector[i], vector[i - data->map->array_size - 1], data);
	}
}
