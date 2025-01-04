/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 16:50:46 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_specifier(t_format *format, va_list args, int *printed_chars)
{
//	if (format-> f_specifier == 'c')
//		print_char_with_format((char)va_arg(args, int), format, printed_chars);
	if (format-> f_specifier == 's')
		print_padding(va_arg(args, char *), format, printed_chars);
	else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
		print_i_formatted(va_arg(args, int), format, printed_chars);
//	else if (format-> f_specifier == 'u')
//		print_unsigned_with_format(va_arg(args, unsigned int), format, printed_chars);
//	else if (format-> f_specifier == 'x')
//		print_hex_with_format(va_arg(args, unsigned int), format, 0, printed_chars);
//	else if (format-> f_specifier == 'X')
//		print_hex_with_format(va_arg(args, unsigned int), format, 1, printed_chars);
}
