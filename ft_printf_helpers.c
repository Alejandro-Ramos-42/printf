/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:20:33 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 19:59:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	parse_flags(const char **str, t_format *format)
{
	while (**str == '-' || **str == '0' || **str == '#' || \
**str == '+' || **str == ' ')
	{
		if (**str == '-')
			format -> flags |= FLAG_MINUS;
		if (**str == '0')
			format -> flags |= FLAG_ZERO;
		if (**str == '#')
			format -> flags |= FLAG_HASH;
		if (**str == '+')
			format -> flags |= FLAG_PLUS;
		if (**str == ' ')
			format -> flags |= FLAG_SPACE;
		(*str)++;
	}
}

void	parse_width(const char **str, t_format *format, va_list args)
{
	if (**str >= '0' && **str <= '9')
	{
		format -> width = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		format -> width = va_arg(args, int);
		(*str)++;
	}
}

void	parse_precision(const char **str, t_format *format, va_list args)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str >= '0' && **str <= '9')
		{
			format -> precision = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			format -> precision = va_arg(args, int);
			(*str)++;
		}
		else
			format -> precision = 0;
	}
}

void	parse_specifier(const char **str, t_format *format)
{
	format -> specifier = **str;
	(*str)++;
}
