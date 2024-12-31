/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:20:33 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 15:23:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	parse_flags(const char **str, t_format *format)
{
	while (**str == '-' || **str == '0' || **str == '#' || **str == '+' || **str == ' ')
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

void	parse_width (const char **str, t_format *format, va_list args)
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
