/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/05 18:20:20 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_dec_to_hex(int n)
{
	unsigned int	num_in_dec;
	char			*num_in_hex;
	char			*lookup_array;
	int				i;

	num_in_dec = (unsigned int)n;
	num_in_hex = malloc (9 * sizeof (char));
	if (!num_in_hex)
		return (NULL);
	lookup_array = "0123456789abcdef";
	num_in_hex[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		num_in_hex[i] = lookup_array[num_in_dec % 16];
		num_in_dec /= 16;
		i--;
	}
	i = 0;
	while (num_in_hex[i] == '0' && i < 8)
		i++;
	return (num_in_hex + i);
}

int	ft_print_hex(int n)
{
	int		counter;
	char	*hex_num;

	counter = 0;
	hex_num = convert_dec_to_hex(n);
	if (hex_num)
	{
		counter += ft_putstr_fd(hex_num, 1);
		free(hex_num - (8 - ft_strlen(hex_num)));
	}
	return (counter);
}
