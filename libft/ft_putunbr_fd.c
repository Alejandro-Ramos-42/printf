/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:34:34 by alex              #+#    #+#             */
/*   Updated: 2025/01/05 16:13:28 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	count++;
	return (count);
}

//int	main(void)
//{
//	ft_putnbr_fd(-2147483648LL, 1);
//}
