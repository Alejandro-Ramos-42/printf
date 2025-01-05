/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2025/01/05 15:16:43 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_specifier(t_format *format, va_list *args, int *printed_chars)
{
	char *str;

	if (format-> f_specifier == 'c')
		*printed_chars += ft_putchar_fd((char)va_arg(*args, int), 1);
	else if (format-> f_specifier == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			str = "(null)";
		*printed_chars += ft_putstr_fd(str, 1);
	}
	else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
		*printed_chars += ft_putnbr_fd(va_arg(*args, int), 1);
//	else if (format-> f_specifier == 'u')
//		print_unsigned_with_format(va_arg(args, unsigned int), format, printed_chars);
//	else if (format-> f_specifier == 'x')
//		print_hex_with_format(va_arg(args, unsigned int), format, 0, printed_chars);
//	else if (format-> f_specifier == 'X')
//		print_hex_with_format(va_arg(args, unsigned int), format, 1, printed_chars);
}
