/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/11 12:42:12 by aramos           ###   ########.fr       */
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
	if (format -> width > len)//width more than len, pad
		padding = format -> width - len;
	if (format -> width == '*' && va_arg(args, int) > len)//arg more than len, pads
		padding = va_arg(args, int) - len;
	if (format -> precision >= 0 && format -> precision < len)//precision less than len, cuts
		len = format -> precision;
	if (format -> width > format -> precision && format -> precision != -1)//width more than precision, pads
		padding = format -> width - format -> precision;
	if (!(format -> flags & FLAG_MINUS))//check if pad is on the left
	{
		while (padding--) 
			(*printed_chars) += ft_putchar_fd(' ', 1);
	}
	write(1, str, len);//prints with pad if necessary
	*printed_chars += len;
	if (format -> flags & FLAG_MINUS && format -> f_specifier != 'd'
			&& format -> f_specifier != 'i')//check if we need to pad to the left
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
	int		flag;

	str = ft_itoa(n);
	len = ft_strlen(str);
	padding = 0;
	flag = 0;
	if (format -> width > len || format -> precision > len)
	{
		if (format -> width > len)
			padding = format -> width - len;
		else if (format -> precision > len)
		{
			padding = format -> precision - len;
			flag = 1;
		}
		if (!(format -> flags & FLAG_MINUS))//check if pad is on the left side
		{
			if (format -> flags & FLAG_ZERO)//pad with 0s
				pad_helper(padding, '0', printed_chars, flag);
			else
				pad_helper(padding, ' ', printed_chars, flag);
		}
		(*printed_chars) += ft_putstr_fd(str, 1);
		if ((format -> flags & FLAG_MINUS))//check if pad is on the right side
			pad_helper(padding, ' ', printed_chars, 0);
	}
	else
		(*printed_chars) += ft_putstr_fd(str, 1);
	free(str);
}

void	pad_helper(int padding, char c, *printed_chars, int flag)
{
	while (pading--)
	{
		(*printed_chars) += ft_putchar_fd(c, 1);
	}
}
//
//char	*pbonus_di_helper(t_format *format, int len)
//{
//	char	*str;
//	int		padding;
//
//	if (format -> width > len)
//		padding = format -> width - len;
//	else if (format -> precision > len)
//		padding = format -> precision - len;
//	str = malloc((padding + len + 1) * sizeof(char));
//	if (!str)
//		return (NULL);
//	return (str);
//}
//
//void	pbonus_uformatted(unsigned int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//
//	str = ft
//}
