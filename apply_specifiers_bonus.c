/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2025/01/11 10:40:20 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_specifier(t_format *format, va_list args, int *printed_chars)
{
	//const char	*str;
	if (format-> f_specifier == 'c')
		pbonus_c((char)va_arg(args, int), format, printed_chars);
//	(*str)++;
//	if (format-> f_specifier == 's')
//	{
//		str = va_arg(args, char *);
//		if (!str)
//			str = "(null)";
//		print_padding(str, format, args, printed_chars);
//	}
//	else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
//		print_i_formatted(va_arg(args, int), format, args, printed_chars);
//	else if (format-> f_specifier == 'u')
//		print_unsigned_with_format(va_arg(args, unsigned int), format, printed_chars);
//	else if (format-> f_specifier == 'x')
//		print_hex_with_format(va_arg(args, unsigned int), format, 0, printed_chars);
//	else if (format-> f_specifier == 'X')
//		print_hex_with_format(va_arg(args, unsigned int), format, 1, printed_chars);
	else if (format-> f_specifier == '%')
		*printed_chars += ft_putchar_fd('%', 1);
}
