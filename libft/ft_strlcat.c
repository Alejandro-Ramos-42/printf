/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:48:43 by aramos            #+#    #+#             */
/*   Updated: 2024/12/03 11:19:28 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	j = len_dst;
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] != '\0' && j < size - 1)
	{
		dst [j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_dst + len_src);
}

//int	main(void)
//{
//	char	dst[6] = "Hello.";
//	char	src[11] = " Cat";
//
//	printf("\n%zu\n",  ft_strlcat(dst, src, 4));
//	printf("%s", dst);
//	return (0);
//}
