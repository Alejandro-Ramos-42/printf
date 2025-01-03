/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:15:55 by aramos            #+#    #+#             */
/*   Updated: 2024/12/06 19:27:05 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		size_s;

	size_s = ft_strlen(s) + 1;
	if (s == NULL)
		return (NULL);
	ptr = (char *) ft_calloc(size_s, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, size_s);
	return (ptr);
}

//int	main(void)
//{
//	char	*s = ft_strdup((char *) "coucou");
//	printf("%s", s);
//	return (0);
//}
