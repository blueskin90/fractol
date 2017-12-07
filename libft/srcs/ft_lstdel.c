/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:54:58 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 06:06:16 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	ptr = *alst;
	while (ptr && del)
	{
		del((*alst)->content, (*alst)->content_size);
		ptr = ptr->next;
		free(*alst);
		*alst = ptr;
	}
	*alst = NULL;
}
