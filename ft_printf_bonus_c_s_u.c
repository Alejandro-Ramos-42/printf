/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_c_s_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 06:13:54 by aramos            #+#    #+#             */
/*   Updated: 2025/01/17 16:15:01 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	hm_pudding(int len, t_format *format, int *printed_chars);
static void	pbonus_s_pad(int padding, int *printed_chars);

//%c speficier
void	pbonus_c(char c, t_format *format, int *printed_chars)
{
	int		padding;

	padding = format -> width - 1;
	if (!(format -> flags & FLAG_MINUS))
	{
		while (padding-- > 0)
			(*printed_chars) += ft_putchar_fd(' ', 1);
	}
	(*printed_chars) += ft_putchar_fd(c, 1);
	if (format -> flags & FLAG_MINUS)
	{
		while (padding-- > 0)
			(*printed_chars) += ft_putchar_fd(' ', 1);
	}
}

//%s specifier
void	pbonus_s(const char *str, t_format *format
		, va_list args, int *printed_chars)
{
	int	len;
	int	padding;

	len = ft_strlen(str);
	padding = 0;
	if (format -> width > len)
		padding = format -> width - len;
	if (format -> width == '*' && va_arg(args, int) > len)
		padding = va_arg(args, int) - len;
	if (format -> precision >= 0 && format -> precision < len)
		len = format -> precision;
	if (format -> width > format -> precision && format -> precision != -1)
		padding = format -> width - format -> precision;
	if (!(format -> flags & FLAG_MINUS))
		pbonus_s_pad(padding, printed_chars);
	write(1, str, len);
	*printed_chars += len;
	if (format -> flags & FLAG_MINUS
		&& format -> f_specifier != 'd' && format -> f_specifier != 'i')
		pbonus_s_pad(padding, printed_chars);
}

static void	pbonus_s_pad(int padding, int *printed_chars)
{
	while (padding--)
		(*printed_chars) += ft_putchar_fd(' ', 1);
}

//%u specifier
void	pbonus_u(unsigned int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;

	str = ft_printf_utoa(n);
	if (n == 0 && (format -> precision == 0 || format -> width == 0))
		len = 0;
	else
		len = append_0(&str, format);
	if (!(format -> flags & FLAG_MINUS))
		hm_pudding(len, format, printed_chars);
	if (!(n == 0 && (format -> precision == 0 || format -> width == 0)))
		(*printed_chars) += ft_putstr_fd(str, 1);
	format -> pad = ' ';
	if (format -> flags & FLAG_MINUS)
		hm_pudding(len, format, printed_chars);
	free(str);
}

static void	hm_pudding(int len, t_format *format, int *printed_chars)
{
	int		padding;

	padding = 0;
	if (format -> width > len)
		padding = format -> width - len;
	if (format -> flags & FLAG_ZERO)
		format -> pad = '0';
	while (padding--)
		(*printed_chars) += ft_putchar_fd(format -> pad, 1);
}
