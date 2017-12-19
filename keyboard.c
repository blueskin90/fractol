/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:21:23 by toliver           #+#    #+#             */
/*   Updated: 2017/12/15 20:34:44 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_on(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && data->onscreen->ite != 2147483647)
		data->onscreen->ite++;
	if (keycode == 78 && data->onscreen->ite != 0)
		data->onscreen->ite--;
	if (keycode == 49)
		data->onscreen->locked = (data->onscreen->locked == 0 ? 1 : 0);
	if (keycode == 46)
		data->menu = (data->menu == 0 ? 1 : 0);
	if (keycode == 69 || keycode == 78 || keycode == 46)
	{
		ft_refresh(data);
		ft_printite(data);
	}
	return (0);
}
