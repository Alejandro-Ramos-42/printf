/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:31:38 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 15:37:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

//void	parse_width(const char **str, t_format *format, va_list args)
//{
//}

static void	check_specifier(t_format *format, char c)
{
	if (c == 'c')
		format ->f_specifier = SPEC_C;
	else if (c == 's')
		format ->f_specifier = SPEC_S;
	else if (c == 'p')
		format ->f_specifier = SPEC_P;
	else if (c == 'd')
		format ->f_specifier = SPEC_D;
	else if (c == 'i')
		format ->f_specifier = SPEC_I;
	else if (c == 'u')
		format ->f_specifier = SPEC_U;
	else if (c == 'x')
		format ->f_specifier = SPEC_LX;
	else if (c == 'X')
		format ->f_specifier = SPEC_X;
	else
		format -> f_specifier = 0;
}

void	print_char(char c, t_format *format)
{
	if (format -> width > 1 && !(format -> flags & FLAG_MINUS))
	{
		while (--format -> width)
			ft_putchar_fd(' ', 1);
	}
	ft_putchat_fd(c, 1);
	if (format -> width > 1 && (format -> flags & FLAG_MINUS))
	{
		while (--format -> width)
			ft_putchar_fd(' ', 1);
	}
}

static void	apply_specifier(t_format *format, va_list args)
{
	if (format -> f_specifier == SPEC_C)
	{
		print_char((char)va_arg(args, int), format);
	}
	else if (format -> f_specifier == SPEC_S)
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format -> f_specifier == SPEC_D || format -> f_specifier == SPEC I)
		ft_putstr_fd(ft_atoi(va_arg(args, char *)), 1);
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
			format = {.flags = 0, .width = 0, .precision = 0, .f_specifier = 0};
			parse_flags(&str, &format);
			parse_width(&str, &format, args);
			if (*str)
				parse_specifier(&format, *str++);
			apply_specifier(&format, args);
		}
		else
			ft_puchar(*str++, 1);
		printed_chars++;
	}
	va_end(args);
	return (printed_chars);
}
