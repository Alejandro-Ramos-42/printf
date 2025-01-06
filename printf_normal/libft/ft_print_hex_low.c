/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/06 18:18:51 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_dec_to_hex(int n)
{
	unsigned int	num_in_dec;
	char			*num_in_hex;
	char			*lookup_array;
	int				i;

	num_in_hex = malloc(9 * sizeof (char));
	if (!num_in_hex)
		return (NULL);
	num_in_dec = (unsigned int)n;
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

void	ft_strupcase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	ft_print_hex(int n, int	upper)
{
	int		counter;
	char	*hex_num;

	counter = 0;
	if (n == 0)
	{
		counter += ft_putchar_fd('0', 1);
		return (counter);
	}
	hex_num = convert_dec_to_hex(n);
	if (hex_num)
	{
		if (upper == 1)
			ft_strupcase(hex_num);
		counter += ft_putstr_fd(hex_num, 1);
		free(hex_num - (8 - ft_strlen(hex_num)));
	}
	return (counter);
}
