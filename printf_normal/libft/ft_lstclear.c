/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:54:52 by alex              #+#    #+#             */
/*   Updated: 2024/12/25 16:07:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = temp;
	}
}

//int	main(void)
//{
//	t_list	*node;
//	t_list	*sec_node;
//	t_list	*tr_node;
//	t_list	*qua_node;
//
//	node = ft_lstnew("a");
//	printf("Creation of first node: %s\n", (char *)node -> content);
//	printf("Address of FIRST node: %p\n", node);
//	printf("Address of next: %p\n", node -> next);
//	sec_node = ft_lstnew("b");
//	ft_lstadd_back(&node, sec_node);
//	printf("Creation of second node: %s\n", (char *)sec_node -> content);
//	printf("Address of SECOND node: %p\n", sec_node);
//	printf("Address of next: %p\n", sec_node -> next);
//	tr_node = ft_lstnew("c");
//	ft_lstadd_back(&node, tr_node);
//	printf("Creation of third node: %s\n", (char *)tr_node -> content);
//	printf("Address of THIRD node: %p\n", tr_node);
//	printf("Address of next: %p\n", tr_node -> next);
//	qua_node = ft_lstnew("d");
//	ft_lstadd_back(&node, qua_node);
//	printf("Creation of forth node: %s\n", (char *)qua_node -> content);
//	printf("Address of FOURTH node: %p\n", qua_node);
//	printf("Address of next: %p\n", qua_node -> next);
//	printf("%d\n\n", ft_lstsize(node));
//
//	while(node != NULL){
//		printf("content: %s, address: %p -> ", (char *)node-> content, node);
//		node = node -> next;
//	}
//	ft_lstclear(&node, ft_lstdelone);
//	return (0);
//}
