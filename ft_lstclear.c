/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshutko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:34:02 by dshutko           #+#    #+#             */
/*   Updated: 2023/02/28 22:34:10 by dshutko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	p = *lst;
	while (p != NULL)
	{
		*lst = (*lst)->next;
		(del)(p->content);
		free(p);
		p = *lst;
	}
	lst = NULL;
}
