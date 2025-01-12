/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:31:38 by alex              #+#    #+#             */
/*   Updated: 2025/01/12 10:35:05 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	bs(const char **str, t_format *format, va_list args, int *printed_chars)
{
	*format = (t_format){0, 0, -1, 0};
	parse_flags(str, format);
	parse_width(str, format, args);
	parse_precision(str, format, args);
	parse_specifier(str, format);
	apply_specifier(format, args, printed_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			printed_chars;
	t_format	format;
	int			counter;
	int			counter_if;

	printed_chars = 0;
	va_start(args, str);
	counter = 1;
	counter_if = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bs(&str, &format, args, &printed_chars);
			counter++;
		}
		else if (*str != '%')
		{
			counter_if++;
			ft_putchar_fd(*str, 1);
			printed_chars++;
		}
		str++;
	}
	va_end(args);
	return (printed_chars);
}
