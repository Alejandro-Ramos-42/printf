/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 20:42:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	apply_specifiers(t_format *format, va_list args, int *printed_chars)
{
	if (format->specifier == 'c')
		print_char_with_format((char)va_arg(args, int), format, printed_chars);
	else if (format->specifier == 's')
		print_with_padding(va_arg(args, char *), format, printed_chars);
	else if (format->specifier == 'd' || format->specifier == 'i')
		print_number_with_format(va_arg(args, int), format, printed_chars);
	else if (format->specifier == 'u')
		print_unsigned_with_format(va_arg(args, unsigned int), format, printed_chars);
	else if (format->specifier == 'x')
		print_hex_with_format(va_arg(args, unsigned int), format, 0, printed_chars);
	else if (format->specifier == 'X')
		print_hex_with_format(va_arg(args, unsigned int), format, 1, printed_chars);
}
