/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:31:38 by alex              #+#    #+#             */
/*   Updated: 2025/01/05 12:42:10 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bonus(const char **str, t_format *format, va_list args, int *printed_chars)
{
	*format = (t_format){0, 0, -1, 0};
	printf("DEBUG: printed_chars = %d\n", *printed_chars);
	parse_flags(str, format);
	printf("DEBUG: printed_chars = %d\n", *printed_chars);
	parse_width(str, format, args);
	printf("DEBUG: printed_chars = %d\n", *printed_chars);
	parse_precision(str, format, args);
	printf("DEBUG: printed_chars = %d\n", *printed_chars);
	parse_specifier(str, format);
	printf("DEBUG: printed_chars = %d\n", *printed_chars);
	apply_specifier(format, args, printed_chars);
	printf("DEBUG: printed_chars = %d\n", *printed_chars);
}


int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			printed_chars;
	t_format	format;

	printed_chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bonus(&str, &format, args, &printed_chars);
			printf("DEBUG: printed_chars = %d\n", printed_chars);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			printed_chars++;
		}
		str++;
	}
	va_end(args);
	return (printed_chars);
}
