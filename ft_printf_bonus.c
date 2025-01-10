/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:31:38 by alex              #+#    #+#             */
/*   Updated: 2025/01/10 16:58:02 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	bonus(const char **str, t_format *format, va_list args, int *printed_chars)
{
	const char	*cont_str;

	*format = (t_format){0, 0, -1, 0};
	cont_str = *str;
	parse_flags(str, format);
	parse_width(str, format, args);
	parse_precision(str, format, args);
	parse_specifier(str, format);
	apply_specifier(str, format, args, printed_chars);
	//cont_str = 
	//ft_printf(cont_str, args);
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
		}
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			printed_chars++;
		}
		str++;
	}
	va_end(args);
	return (printed_chars);
}
