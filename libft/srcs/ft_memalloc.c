/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:15:24 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 00:01:16 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	i = -1;
	if (!(ptr = (void*)malloc(sizeof(void) * size)) || size == 0)
		return (NULL);
	while (++i < size)
		((char*)ptr)[i] = 0;
	return (ptr);
}
