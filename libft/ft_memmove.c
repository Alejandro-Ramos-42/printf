/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:07:50 by aramos            #+#    #+#             */
/*   Updated: 2024/11/30 10:39:45 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ptr;

	if (n == 0)
		return (dest);
	ptr = dest;
	if (src < dest && dest <= src + (n -1))
	{
		while (n-- > 0)
			*((unsigned char *)dest + n) = *((unsigned const char *)src + n);
	}
	else
		ft_memcpy(dest, src, n);
	return (ptr);
}

//int	main(void)
//{
//	char	src[100] = "abcd"
//
//	memmove(src, src + 2, 4);
//	printf("%s", )
//}
