/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/14 04:54:47 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
void	pbonus_s(const char *str, t_format *format, va_list args, int *printed_chars)
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
	{
		while (padding--) 
			(*printed_chars) += ft_putchar_fd(' ', 1);
	}
	write(1, str, len);
	*printed_chars += len;
	if (format -> flags & FLAG_MINUS && format -> f_specifier != 'd'
			&& format -> f_specifier != 'i')
	{
		while (padding--)
			(*printed_chars) += ft_putchar_fd(' ', 1);
	}
}

//%d and %i specifiers
void	pbonus_di(int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;
	int		m;

	str = ft_printf_itoa(n);
	m = 0;
	if ((format -> flags & FLAG_PLUS))
		str = ft_strjoin(prefix(n, format), str);
	len = ft_strlen(str);
	if (n < 0 && format -> flags & FLAG_ZERO && !(format -> flags & FLAG_MINUS))
	{
		(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
		len++;
	}
	padding = hm_padding(n, len, format, &m, printed_chars);
	if (!(format -> flags & FLAG_MINUS))
		pad_helper(padding, printed_chars, &m);
	(*printed_chars) += ft_putstr_fd(str, 1);
	m = 0;
	if (format -> flags & FLAG_MINUS)
		pad_helper(padding, printed_chars, &m);
	free(str);
}

char	*prefix(int n, t_format *format)
{
	if (n < 0)
		return ("-");
	if (format -> flags & FLAG_PLUS)
		return ("+");
	if (format -> flags & FLAG_SPACE)
		return (" ");
	return ("");
}

int	hm_padding(int n, int len, t_format *format, int *m, int *printed_chars)
{
	int	padding;

	padding = 0;
	if (n < 0 && !(format -> flags & FLAG_ZERO))
	{
		(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
		len++;
	}
	if (format -> precision > len)
	{
		padding = format -> precision - len;
		*m = 1;
	}
	if (format -> width > len)
	{
		padding = format -> width - len;
		if (format -> flags & FLAG_ZERO)
			*m = 1;
	}
	return (padding);
}

void	pad_helper(int padding, int *printed_chars, int *m)
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

//%u specifier
void	pbonus_u(unsigned int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		m;

	str = ft_printf_utoa(n);
	m = 0;
	len = ft_strlen(str);//10
	if ((format -> flags & FLAG_ZERO))//no
	{
		if (format -> flags & FLAG_MINUS)
			format -> flags = ~FLAG_ZERO;
	}
	if (!(format -> flags & FLAG_MINUS))
		hm_pudding(len, format, printed_chars);
	(*printed_chars) += ft_putstr_fd(str, 1);
	if (format -> flags & FLAG_MINUS)
		hm_pudding(len, format, printed_chars);
	free(str);
}

void	hm_pudding(int len, t_format *format, int *printed_chars)
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

