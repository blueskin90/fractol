/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:00:42 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 15:46:15 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			wrd_nbr(char const *s, char c)
{
	unsigned int	i;
	int				wrdnbr;

	i = 0;
	wrdnbr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			i++;
			wrdnbr++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wrdnbr);
}

static char			*wordcut(const char *s, char c)
{
	int				i;
	char			*str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**array;
	int				wrd;

	wrd = 0;
	if (!s || !(array = (char**)malloc(sizeof(char*) * (wrd_nbr(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			if ((array[wrd] = wordcut(s, c)) == NULL)
				return (NULL);
			wrd++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	array[wrd] = 0;
	return (array);
}
