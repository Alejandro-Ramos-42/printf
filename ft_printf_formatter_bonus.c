/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/12 13:00:46 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	pbonus_di(int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;

	str = ft_itoa(n);//-1
	len = ft_strlen(str);//2
	padding = 0;
	if (format -> width > len || format -> precision >= len)
	{
		if (n >= 0)
		{
			(*printed_chars) += ft_putchar_fd('+', 1);
		}
		if (n < 0 && n != -2147483648)
		{
			free(str);
			(*printed_chars) += ft_putchar_fd('-', 1);
			str = ft_itoa(-n);
			if (format -> precision >= len)
				len -= 1;
		}
		if (format -> width > len)
		{
			padding = format -> width - len;
			if (format -> flags & FLAG_MINUS && format -> flags & FLAG_ZERO)
				format -> flags = ~FLAG_ZERO;
			else if (!(format -> flags & FLAG_MINUS) && !(format -> flags & FLAG_ZERO))
				pad_helper(padding, ' ', printed_chars);
		}
		if (format -> precision > len)
		{
			padding = format -> precision - len;
			format -> flags |= FLAG_ZERO;
		}
		if (format -> flags & FLAG_ZERO)
			pad_helper(padding, '0', printed_chars);
		(*printed_chars) += ft_putstr_fd(str, 1);
		if ((format -> flags & FLAG_MINUS && !(format -> flags & FLAG_ZERO)))
			pad_helper(padding, ' ', printed_chars);
	}
	else
		(*printed_chars) += ft_putstr_fd(str, 1);
	free(str);
}
//
//char	*prefix(int n, t_format *format)
//{
//	if (n < 0)
//		return ("-");
//	if (format -> flags & FLAG_PLUS)
//		return ("+");
//	if (format -> flags & FLAG_SPACE)
//		return (" ");
//	return ("");
//}
//
//int	hm_pading(int len, t_format *format)
//{
//	int	padding;
//
//	padding = 0;
//	if (format -> precision > len)
//		padding = format -> precision - len;
//	if (format -> width > len + padding)
//		padding += format -> width - (len + padding);
//}

void	pad_helper(int padding, char c, int *printed_chars)
{
	while (padding--)
		(*printed_chars) += ft_putchar_fd(c, 1);
}

void	pbonus_u(unsigned int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;

	str = ft_itoa(n);
	len = ft_strlen(str);
	padding = 0;
	if (format -> width > len || format -> precision > len)
	{
		if (format -> width > len)
		{
			padding = format -> width - len;
			if (format -> flags & FLAG_MINUS && format -> flags & FLAG_ZERO)
				format -> flags = ~FLAG_ZERO;
			else if (!(format -> flags & FLAG_MINUS) && !(format -> flags & FLAG_ZERO))
				pad_helper(padding, ' ', printed_chars);
		}
		if (format -> precision > len)
		{
			padding = format -> precision - len;
			format -> flags |= FLAG_ZERO;
		}
		if (format -> flags & FLAG_ZERO)
			pad_helper(padding, '0', printed_chars);
		(*printed_chars) += ft_putstr_fd(str, 1);
		if ((format -> flags & FLAG_MINUS && !(format -> flags & FLAG_ZERO)))
			pad_helper(padding, ' ', printed_chars);
	}
	else
		(*printed_chars) += ft_putstr_fd(str, 1);
	free(str);
}

void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars)
{
	if (format -> flags & FLAG_HASH)
		(*printed_chars) += ft_putstr_fd("0x", 1);
	(*printed_chars) += ft_print_hex(n, upp);
}
