/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:24:18 by aramos            #+#    #+#             */
/*   Updated: 2024/11/29 17:57:00 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = '\0';
}
//
//int	main(void)
//{
//	char	str[50] = "Hello, trying bzero now!";
//
//	//printf("Before bzero: %s\n", str);
//	printf("\nBefore ft_bzero: %s\n", str);
//	//bzero(str + 2, 2*sizeof(char));
//	//printf("\nAfter bzero:%s\n", str);
//	//printf("\nAfter bzero:%s\n", str + 4);
//	ft_bzero(str + 2, 2);
//	printf("\nAfter ft_bzero: %s\n", str);
//	printf("\nAfter ft_bzero: %s\n", str + 4);
//	return (0);
//}
