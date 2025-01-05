/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:47:07 by alex              #+#    #+#             */
/*   Updated: 2024/12/28 23:28:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_node = ft_lstnew(f(lst -> content));
	if (!new_node)
		return (NULL);
	new_list = new_node;
	lst = lst -> next;
	while (lst != NULL)
	{
		new_node -> next = ft_lstnew(f(lst -> content));
		if (!new_node -> next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = new_node -> next;
		lst = lst -> next;
	}
	return (new_list);
}
