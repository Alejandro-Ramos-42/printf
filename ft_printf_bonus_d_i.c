/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_d_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/14 08:35:26 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	hm_padding(int n, int len, t_format *format, int *m, int *printed_chars);
static int	pbonus_di_0(int n, t_format *format, int *printed_chars, int *len);
static void	pad_helper(int padding, int *printed_chars, int *m);
static char	*prefix(int n, t_format *format);

//%d and %i specifiers
void	pbonus_di(int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;
	int		m;

	str = ft_printf_itoa(n);//1
	m = 0;
	len = ft_strlen(str);//1
	if (format -> flags & FLAG_ZERO)//no
		m = pbonus_di_0(n, format, printed_chars, &len);
	padding = hm_padding(n, len, format, &m, printed_chars);//
	if (n >= 0 && (format -> flags & FLAG_PLUS || format -> flags & FLAG_SPACE))
	{
		(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
		len++;
	}
	if (!(format -> flags & FLAG_MINUS))
		pad_helper(padding, printed_chars, &m);
	(*printed_chars) += ft_putstr_fd(str, 1);
	m = 0;
	if (format -> flags & FLAG_MINUS)
		pad_helper(padding, printed_chars, &m);
	free(str);
}

static int	pbonus_di_0(int n, t_format *format, int *printed_chars, int *len)
{
	int	m;

	m = 0;
	if (!(format -> flags & FLAG_MINUS))
	{
		if (n < 0 || format -> flags & FLAG_PLUS || format -> flags & FLAG_SPACE)
		{
			(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
			(*len)++;
			m = 1;
		}
	}
	else
	{
		m = 0;
	}
	return (m);
}

static char	*prefix(int n, t_format *format)
{
	if (n < 0)
		return ("-");
	if (format -> flags & FLAG_PLUS)
		return ("+");
	if (format -> flags & FLAG_SPACE)
		return (" ");
	return ("");
}

static int	hm_padding(int n, int len, t_format *format, int *m, int *printed_chars)
{
	int	padding;

	padding = 0;
	if (format -> precision > len)
	{
		if (n < 0 && !(format -> flags & FLAG_ZERO))
			(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
		padding = format -> precision - len;
		*m = 1;
	}
	else if (n < 0 && !(format -> flags & FLAG_ZERO))
	{
		(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
		len++;
	}
	if (format -> width > len)
	{
		padding = format -> width - len;
		if (format -> flags & FLAG_ZERO)
			*m = 1;
	}
	return (padding);
}

static void	pad_helper(int padding, int *printed_chars, int *m)
{
	if (*m == 0)
	{
		while (padding--)
			(*printed_chars) += ft_putchar_fd(' ', 1);
	}
	else if (*m == 1)
	{
		while (padding--)
			(*printed_chars) += ft_putchar_fd('0', 1);
	}
}
