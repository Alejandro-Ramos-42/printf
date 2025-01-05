/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:09:55 by aramos            #+#    #+#             */
/*   Updated: 2024/12/04 19:29:48 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*ptr_l;
	const char	*ptr_b;
	size_t		remaining;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		ptr_b = big;
		ptr_l = little;
		remaining = len;
		while (*ptr_b == *ptr_l && *ptr_l != '\0' && remaining > 0)
		{
			ptr_b++;
			ptr_l++;
			remaining--;
		}
		if (*ptr_l == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

//int	main(void)
//{
//	char	haystack[] = "aaabcabcd";
//	printf("%s", ft_strnstr(haystack, "cd", 5));
//	return (0);
//}
