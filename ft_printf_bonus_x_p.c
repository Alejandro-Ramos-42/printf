/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_x_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 06:18:20 by aramos            #+#    #+#             */
/*   Updated: 2025/01/14 06:19:18 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//%x specifier
void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars)
{
	int		len;
	char	*str;

	str = ft_hxtoa(n, upp);//1
	len = ft_strlen(str);//1
	if ((format -> flags & FLAG_ZERO))///no
	{
		if (format -> flags & FLAG_MINUS)
			format -> flags = ~FLAG_ZERO;
	}
	if (format -> flags & FLAG_HASH && n != 0)//no
	{
		if (upp == 0)
			(*printed_chars) += ft_putstr_fd("0x", 1);
		if (upp == 1)
			(*printed_chars) += ft_putstr_fd("0X", 1);
		len += 2;
	}
	if (!(format -> flags & FLAG_MINUS))
		hx_padding(len, format, printed_chars);//
	(*printed_chars) += ft_print_hex(n, upp);
	if (format -> flags & FLAG_MINUS)
		hx_padding(len, format, printed_chars);//
	free(str);
}

void	hx_padding(int len, t_format *format, int *printed_chars)
{
	int		padding;
	char	c;

	padding = 0;
	if (format -> width > len)//yes
		padding = format -> width - len;//pad = 3-1 = 2
	if (format -> flags & FLAG_ZERO)//no
		c = '0';
	else
		c = ' ';//pad with ' '
	if (format -> precision > len)//no
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

void	p_padding(int len, t_format *format, int *printed_chars)
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
