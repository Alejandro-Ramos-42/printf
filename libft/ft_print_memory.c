/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/06 18:50:05 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_addr_to_hex(void *addr)
{
	unsigned long	address_in_dec;
	char			*address_in_hex;
	char			*lookup_array;
	int				i;

	address_in_dec = (unsigned long)addr;
	address_in_hex = malloc (17 * sizeof (char));
	if (!address_in_hex)
		return (NULL);
	lookup_array = "0123456789abcdef";
	address_in_hex[16] = '\0';
	i = 15;
	while (i >= 0)
	{
		address_in_hex[i] = lookup_array[address_in_dec % 16];
		address_in_dec /= 16;
		i--;
	}
	i = 0;
	while (address_in_hex[i] == '0' && i < 15)
		i++;
	return (address_in_hex + i);
}

int	ft_print_memory(void *addr)
{
	char	*converted;
	int		counter;

	counter = 0;
	if (addr == NULL)
		return (ft_putstr_fd(("(nil)"), 1));
	converted = convert_addr_to_hex((char *)addr);
	if (!converted)
		return (0);
	counter += ft_putstr_fd("0x", 1);
	counter += ft_putstr_fd(converted, 1);
	free(converted - (16 - strlen(converted)));
	return (counter);
}
