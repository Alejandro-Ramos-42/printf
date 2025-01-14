/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:41:11 by alex              #+#    #+#             */
/*   Updated: 2025/01/14 11:38:26 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_specifier(t_format *format, va_list *args, int *printed_chars)
{
	char	*str;

	if (format-> f_specifier == 'c')
		*printed_chars += ft_putchar_fd((char)va_arg(*args, int), 1);
	else if (format-> f_specifier == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			str = "(null)";
		*printed_chars += ft_putstr_fd(str, 1);
	}
	else if (format-> f_specifier == 'p')
		*printed_chars += ft_print_memory(va_arg(*args, int *));
	else if (format-> f_specifier == 'd' || format-> f_specifier == 'i')
		*printed_chars += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format-> f_specifier == 'u')
		*printed_chars += ft_putunbr_fd(va_arg(*args, int), 1);
	else if (format-> f_specifier == 'x')
		*printed_chars += ft_print_hex_normal_x(va_arg(*args, int), 0);
	else if (format-> f_specifier == 'X')
		*printed_chars += ft_print_hex_normal_x(va_arg(*args, int), 1);
	else if (format-> f_specifier == '%')
		*printed_chars += ft_putchar_fd('%', 1);
}
