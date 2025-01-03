/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:19 by aramos            #+#    #+#             */
/*   Updated: 2024/12/10 15:35:23 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_c(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			words++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char const	*start_w;
	char const	*finish_w;
	size_t		n_strings;
	char		**array;
	int			i;

	i = 0;
	n_strings = word_c(s, c);
	array = malloc((n_strings + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		start_w = s;
		while (*s != c && *s != '\0')
			s++;
		finish_w = s;
		if (start_w != finish_w)
			array[i++] = ft_substr(start_w, 0, finish_w - start_w);
	}
	array [i] = NULL;
	return (array);
}

//
//int	main(void)
//{
//	const char	*s;
//	char		**array;
//
//	s = "hello   h o w are you?";
//	array = ft_split(s, ' ');
//	printf("%s", array[1]);
//}
