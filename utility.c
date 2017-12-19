/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:31:08 by toliver           #+#    #+#             */
/*   Updated: 2017/12/15 20:37:44 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_printite(t_data *data)
{
	char	*str;

	str = ft_itoa(data->onscreen->ite);
	mlx_string_put(data->mlx, data->win, 20, 20, 0xffffff, str);
	free(str);
}
