/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:56:49 by aramos            #+#    #+#             */
/*   Updated: 2024/12/08 14:04:55 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*first;
	unsigned const char	*second;

	i = 0;
	first = (unsigned const char *) s1;
	second = (unsigned const char *) s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	return (first[i] - second[i]);
}

//int	main(void)
//{
//	//const char	s1[] = "1234";
//	//const char	s2[] = "1235";
//
//	printf("Mine: %d\n", ft_strncmp("test\200", "test\0", 6));
//	printf("Original: %d", strncmp("test\200", "test\0", 6));
//	return (0);
//}