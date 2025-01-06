/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/06 19:24:14 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(const char *str, t_format *format, int *printed_chars)
{
	int	len;
	int	padding;

	len = ft_strlen(str);
	if (format -> precision >= 0 && format -> precision < len) //Obtain max chars to print
		len = format -> precision;
	padding = 0;
	if (format -> width > len)
		padding = format -> width - len; //Obtain amount to pad after
	if (!(format -> flags & FLAG_MINUS))
	{
		while (padding--)
		{
			ft_putchar_fd(' ', 1);
			(*printed_chars)++;
		}
	}
	write(1, str, len);
	*printed_chars += len;
	if (format -> flags & FLAG_MINUS)
	{
		while (padding--)
		{
			ft_putchar_fd(' ', 1);
			(*printed_chars)++;
		}
	}
}

void	print_i_formatted(int n, t_format *format, int *printed_chars)
{
	char	*str;

	str = ft_itoa(n);
	print_padding(str, format, printed_chars);
	free (str);
}
//
//void	print_u_formatted(unsigned int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//
//	str = ft
//}
