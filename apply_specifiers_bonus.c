/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2025/01/08 19:22:07 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_specifier(t_format *format, va_list args, int *printed_chars)
{
	const char	*str;
//	if (format-> f_specifier == 'c')
//		print_char_with_format((char)va_arg(args, int), format, printed_chars);
	if (format-> f_specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		print_padding(str, format, args, printed_chars);
	}
	else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
		print_i_formatted(va_arg(args, int), format, args, printed_chars);
//	else if (format-> f_specifier == 'u')
//		print_unsigned_with_format(va_arg(args, unsigned int), format, printed_chars);
//	else if (format-> f_specifier == 'x')
//		print_hex_with_format(va_arg(args, unsigned int), format, 0, printed_chars);
//	else if (format-> f_specifier == 'X')
//		print_hex_with_format(va_arg(args, unsigned int), format, 1, printed_chars);
}
//
//void	apply_specifier(t_format *format, va_list *args, int *printed_chars)
//{
//	char	*str;
//
//	if (format-> f_specifier == 'c')
//		*printed_chars += ft_putchar_fd((char)va_arg(*args, int), 1);
//	else if (format-> f_specifier == 's')
//	{
//		str = va_arg(*args, char *);
//		if (!str)
//			str = "(null)";
//		*printed_chars += ft_putstr_fd(str, 1);
//	}
//	else if (format-> f_specifier == 'p')
//		*printed_chars += ft_print_memory(va_arg(*args, int *));
//	else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
//		*printed_chars += ft_putnbr_fd(va_arg(*args, int), 1);
//	else if (format-> f_specifier == 'u')
//		*printed_chars += ft_putunbr_fd(va_arg(*args, int), 1);
//	else if (format-> f_specifier == 'x')
//		*printed_chars += ft_print_hex(va_arg(*args, int), 0);
//	else if (format-> f_specifier == 'X')
//		*printed_chars += ft_print_hex(va_arg(*args, int), 1);
//	else if (format-> f_specifier == '%')
//		*printed_chars += ft_putchar_fd('%', 1);
//}
