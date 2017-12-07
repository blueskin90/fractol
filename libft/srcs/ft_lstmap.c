/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:45:47 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 02:43:20 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *start;

	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	start = newlist;
	if (lst && f)
	{
		*newlist = *(f(lst));
		while (lst->next)
		{
			lst = lst->next;
			if (!(newlist->next = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			newlist = newlist->next;
			*newlist = *f(lst);
		}
	}
	return (start);
}
