/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:48:41 by toliver           #+#    #+#             */
/*   Updated: 2017/11/12 05:31:47 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*st;

	if (!(st = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	size = -1;
	while (str[++size])
		st[size] = str[size];
	st[size] = '\0';
	return (st);
}
