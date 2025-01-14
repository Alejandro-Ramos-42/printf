/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:31:38 by alex              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/14 00:53:00 by aramos           ###   ########.fr       */
=======
/*   Updated: 2025/01/14 04:12:52 by aramos           ###   ########.fr       */
>>>>>>> new_branch
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(const char **str, t_format *format)
{
	format -> f_specifier = **str;
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
			parse_specifier(&str, &format);
			apply_specifier(&format, &args, &printed_chars);
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
