/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/14 03:10:06 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_memory(void *addr)
{
	int		counter;
	unsigned long	address_in_dec;

	counter = 0;
	address_in_dec = (unsigned long) addr;
	if (addr == NULL)
		return (ft_putstr_fd(("(nil)"), 1));
	counter += ft_putstr_fd("0x", 1);
	counter += ft_print_hex(address_in_dec, 0);
	return (counter);
}
