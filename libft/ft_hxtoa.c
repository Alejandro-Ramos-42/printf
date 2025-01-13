/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/13 23:29:32 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hxtoa(int n)
{
	unsigned int	num_in_dec;
	unsigned int	temp;
	char			*num_in_hex;
	char			*lookup_array;
	int				len;

	num_in_dec = (unsigned int)n;
	temp = num_in_dec;
	len = 0;
	if (n == 0)
		len = 1;
	else
	{
		while (temp > 0)
		{
			temp /= 16;
			len++;
		}
	}
	num_in_hex = malloc((len + 1) * sizeof (char));
	if (!num_in_hex)
		return (NULL);
	lookup_array = "0123456789abcdef";
	num_in_hex[len] = '\0';
	while (len > 0)
	{
		num_in_hex[--len] = lookup_array[num_in_dec % 16];
		num_in_dec /= 16;
	}
	return (num_in_hex);
}
