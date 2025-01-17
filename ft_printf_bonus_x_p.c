/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_x_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 06:18:20 by aramos            #+#    #+#             */
/*   Updated: 2025/01/17 16:25:50 by aramos           ###   ########.fr       */
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
	if (n == 0 && (format -> width == 0 || format -> precision == 0))
		len = 0;
	else
		len = append_0(&str, format);
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
	if(!(n == 0 && (format -> width == 0 || format -> precision == 0)))
		(*printed_chars) += ft_putstr_fd(str, 1);
	if (format -> flags & FLAG_MINUS)
		hx_padding(len, format, printed_chars);
	free(str);
}

static void	hx_padding(int len, t_format *format, int *printed_chars)
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

//%p specifier
void	pbonus_p(void *address, t_format *format, int *printed_chars)
{
	unsigned long	number;
	char			*hex;
	char			*str;
	int				len;

	number = (unsigned long)address;
	hex = ft_hxtoa(number, 0);
	if (!address)
	{
		str = malloc(6 * sizeof(char));
		ft_strlcpy(str, "(nil)", 6);
	}
	else
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
