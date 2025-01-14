/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/14 00:27:23 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_hxtoa(int n, int upp)
{
	unsigned int	num;
	char			*num_in_hex;
	char			*lookup_array;
	int				len;

	num = (unsigned int)n;
	len = 0;
	if (n == 0)
		len = 1;
	else
		len = get_len(num);
	num_in_hex = malloc((len + 1) * sizeof (char));
	if (!num_in_hex)
		return (NULL);
	lookup_array = "0123456789abcdef";
	num_in_hex[len] = '\0';
	while (len > 0)
	{
		num_in_hex[--len] = lookup_array[num_in_dec % 16];
		num /= 16;
	}
	if (upp == 1)
		x_to_alpha(num_in_hex);
	return (num_in_hex);
}

void	x_to_alpha(*c)
{
	if (c && *c)
		*c = (char)ft_toupper(*c);
}
