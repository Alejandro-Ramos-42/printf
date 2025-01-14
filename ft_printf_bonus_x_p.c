/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_x_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 06:18:20 by aramos            #+#    #+#             */
/*   Updated: 2025/01/14 11:44:38 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	p_padding(int len, t_format *format, int *printed_chars);
static void	hx_padding(int len, t_format *format, int *printed_chars);

//%x specifier
void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars)
{
	int		len;
	char	*str;

	str = ft_hxtoa(n, upp);
	len = ft_strlen(str);
	if ((format -> flags & FLAG_ZERO))
	{
		if (format -> flags & FLAG_MINUS)
			format -> flags = ~FLAG_ZERO;
	}
	if (format -> flags & FLAG_HASH && n != 0)
	{
		if (upp == 0)
			(*printed_chars) += ft_putstr_fd("0x", 1);
		if (upp == 1)
			(*printed_chars) += ft_putstr_fd("0X", 1);
		len += 2;
	}
	if (!(format -> flags & FLAG_MINUS))
		hx_padding(len, format, printed_chars);
	(*printed_chars) += ft_print_hex(n, upp);
	if (format -> flags & FLAG_MINUS)
		hx_padding(len, format, printed_chars);
	free(str);
}

static void	hx_padding(int len, t_format *format, int *printed_chars)
{
	int		padding;
	char	c;

	padding = 0;
	if (format -> width > len)
		padding = format -> width - len;
	if (format -> flags & FLAG_ZERO)
		c = '0';
	else
		c = ' ';
	if (format -> precision > len)
	{
		padding = format -> precision - len;
		c = '0';
	}
	while (padding--)
		(*printed_chars) += ft_putchar_fd(c, 1);
}

//%p specifier
void	pbonus_p(void *address, t_format *format, int *printed_chars)
{
	unsigned long	number;
	char			*hex;
	char			*str;
	int				len;

	if (address == 0)
		(*printed_chars) += ft_putstr_fd("(nil)", 1);
	number = (unsigned long)address;
	hex = ft_hxtoa(number, 0);
	if (address == 0)
		(*printed_chars) += ft_putstr_fd("(nil)", 1);
	str = ft_strjoin("0x", hex);
	len = ft_strlen(str);
	if (!(format -> flags & FLAG_MINUS))
		p_padding(len, format, printed_chars);
	(*printed_chars) += ft_putstr_fd(str, 1);
	if (format -> flags & FLAG_MINUS)
		p_padding(len, format, printed_chars);
	free(hex);
	free(str);
}

static void	p_padding(int len, t_format *format, int *printed_chars)
{
	int		padding;

	padding = 0;
	if (format -> width > len)
		padding = format -> width - len;
	if (format -> precision > len)
		padding = format -> precision - len;
	while (padding--)
		(*printed_chars) += ft_putchar_fd(' ', 1);
}
