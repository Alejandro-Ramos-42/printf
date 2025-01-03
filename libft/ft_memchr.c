/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:30:26 by aramos            #+#    #+#             */
/*   Updated: 2024/12/07 14:05:02 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		if (*(const unsigned char *)s != (unsigned char)c)
			s++;
	}
	return (NULL);
}

//int	main(void)
//{
//	char	s[] = {0, 1, 2 ,3 ,4 ,5};
//	//int	i;
//
//	//for (i = 0; i < 5; i++)
//	//	printf("%d\n", *(int *)memchr(s, 52, 5));
//	printf("%p\n", s);
//	printf("%p", ft_memchr(s, 2, 3));
//	return (0);
//}