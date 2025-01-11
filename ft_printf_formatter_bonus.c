/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/11 10:38:01 by aramos           ###   ########.fr       */
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
	return ;
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
	if (format -> width > format -> precision)//width more than precision, pads
		padding = format -> width - format -> precision;
	if (!(format -> flags & FLAG_MINUS))//check if pad is needed to the right(default)
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
//
//	if (!(format -> flags & FLAG_MINUS))//check if pad is needed to the right(default)
//	{
//		while (padding--)
//			(*printed_chars) += ft_putchar_fd(' ', 1);
//	}
//	write(1, str, len);
//	*printed_chars += (len + 1);
//	if (format -> flags & FLAG_MINUS)//check if we need to pad to the left
//	{
//		while (padding--)
//			(*printed_chars) += ft_putchar_fd(' ', 1);
//	}
//}
//
//void	pbonus_di(int n, t_format *format, va_list args, int *printed_chars)
//{
//	char	*str;
//	int		len;
//	int		padding;
//	char	*new_str;
//
//	str = ft_itoa(n);
//	len = ft_strlen(str);
//	padding = 0;
//	if (format -> width > len || format -> precision > len)
//	{
//		padding = format -> width - len;
//		new_str = malloc((padding + len + 1) * sizeof(char));
//		if (!new_str)
//			return ;
//		if (format -> flags & FLAG_ZERO)//pad with 0s
//			ft_memset(new_str, '0', padding);
//		else
//			ft_memset(new_str, ' ', padding);//pad with spaces
//		ft_strlcpy(new_str + padding, str, len + 1);
//
//	}
//	else
//		new_str = ft_strdup(str);
//	print_padding(new_str, format, args, printed_chars);
//	free (str);
//	free (new_str);
//}
//
//void	pbonus_uformatted(unsigned int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//
//	str = ft
//}
