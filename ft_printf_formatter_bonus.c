/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/08 15:11:25 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_padding(const char *str, t_format *format, va_list args, int *printed_chars)
{
	int	len;
	int	padding;

	len = ft_strlen(str);
	padding = 0;
	if (format -> width > len)//width more than len. pads
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

void	print_i_formatted(int n, t_format *format, va_list args, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;
	char	*new_str;

	str = ft_itoa(n);
	len = ft_strlen(str);
	padding = 0;
	if (format -> width > len || format -> precision > len)
	{
		if (format -> flags & FLAG_ZERO)
		{
			padding = format -> width - len;
			if (format -> flags & FLAG_ZERO)
				new_str = ft_bzero(malloc((padding + len + 1) * sizeof(char)), padding);
			else
				new_str = ft_bspace(malloc((padding + len + 1) * sizeof(char)), padding);
			new_str[padding - 1] = '\0';
			ft_strlcat(new_str, str, (padding + len + 1));
		}

	}
	print_padding(new_str, format, args, printed_chars);
	free (str);
}

//void	print_u_formatted(unsigned int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//
//	str = ft
//}
