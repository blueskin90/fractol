/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:51:43 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 15:48:43 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s1[++i])
		;
	while (s2[++j])
		;
	if (!(str = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1u;
	j = -1u;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
