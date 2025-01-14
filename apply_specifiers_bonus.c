/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifiers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2025/01/14 02:00:57 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_specifier(t_format *format, va_list args, int *printed_chars)
{
	const char		*str;
	unsigned int	number;

	if (format-> f_specifier == 'c')
		pbonus_c((char)va_arg(args, int), format, printed_chars);
	if (format-> f_specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		pbonus_s(str, format, args, printed_chars);
	}
	//else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
	//	pbonus_di(va_arg(args, int), format, printed_chars);
	else if (format-> f_specifier == 'u')
	{
		number = (unsigned int) va_arg(args, int);
		pbonus_u(number, format, printed_chars);
	}
	else if (format-> f_specifier == 'x')
	{
		number = (unsigned )va_arg(args, int);
		if ( number == 0)
			*(printed_chars) += ft_putchar_fd('0', 1);
		else
			print_hx(number, format, 0, printed_chars);
	}
	else if (format-> f_specifier == 'X')
	{
		number = va_arg(args, int);
		if ( number == 0)
			*(printed_chars) += ft_putchar_fd('0', 1);
		else
			print_hx(number, format, 1, printed_chars);
	}
	else if (format-> f_specifier == '%')
		*printed_chars += ft_putchar_fd('%', 1);
}
