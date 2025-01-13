/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/13 20:17:45 by aramos           ###   ########.fr       */
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
//
//void	pbonus_di(int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//	int		len;
//	int		padding;
//	int		m;
//
//	str = ft_printf_itoa(n);//9
//	m = 0;
//	if ((format -> flags & FLAG_PLUS))//no
//		str = ft_strjoin(prefix(n, format), str);
//	len = ft_strlen(str);//1
//	if (n < 0 && format -> flags & FLAG_ZERO && !(format -> flags & FLAG_MINUS))//yes
//	{
//		(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
//		len++;
//	}
//	padding = hm_padding(n, len, format, &m, printed_chars);
//	if (!(format -> flags & FLAG_MINUS))//no
//		pad_helper(padding, printed_chars, &m);
//	(*printed_chars) += ft_putstr_fd(str, 1);//prints 1
//	m = 0;
//	if (format -> flags & FLAG_MINUS)//yes
//		pad_helper(padding, printed_chars, &m);//prints 0 pads
//	free(str);
//}
//
char	*prefix(int n, t_format *format)
{
	if (n < 0)//yes
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
	if (n < 0 && !(format -> flags & FLAG_ZERO))//yes, prints '-'
	{
		(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
		len++;//len 2
	}
	if (format -> precision > len)//no
	{
		padding = format -> precision - len;
		*m = 1;
	}
	if (format -> width > len)//no
	{
		padding = format -> width - len;//
		if (format -> flags & FLAG_ZERO)//no
			*m = 1;//m = 0
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
	else if (*m == 1)//yes
	{
		while (padding--)
			(*printed_chars) += ft_putchar_fd('0', 1);//prints 00
	}
}

void	pbonus_u(unsigned int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;
	int		m;

	str = ft_printf_itoa(n);
	m = 0;
	if (format -> flags & FLAG_PLUS && !(format -> flags & FLAG_ZERO))
	{
		free(str);
		str = ft_strjoin("+", ft_printf_itoa(n));
	}
	len = ft_strlen(str);
	if ((format -> flags & FLAG_ZERO))
	{
		if (format -> flags & FLAG_PLUS)
		{
			(*printed_chars) += ft_putstr_fd("+", 1);
			len += 1;
		}
		if (format -> flags & FLAG_MINUS)
			format -> flags = ~FLAG_ZERO;
	}
	padding = hm_padding(n, len, format, &m, printed_chars);
	pad_helper(padding, printed_chars, &m);
	(*printed_chars) += ft_putstr_fd(str, 1);
	pad_helper(padding, printed_chars, &m);
	free(str);
}
//void	pbonus_di(int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//	int		len;
//	int		padding;
//
//	str = ft_itoa(n);//14
//	len = ft_strlen(str);//2
//	padding = 0;
//	if (format -> width > len || format -> precision >= len)//yes
//	{
//		if (n >= 0 && (format -> flags & FLAG_PLUS) && (format -> flags & FLAG_ZERO))//no
//			(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
//		if (n < 0 && (format -> flags & FLAG_ZERO))//no
//			(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);
//		padding = hm_padding(len, format);//1
//		if (!(format -> flags & FLAG_MINUS))
//			pad_helper(padding, ' ', printed_chars);//prints ' '
//		(*printed_chars) += ft_putstr_fd(str, 1);//prints '14'
//		if ((format -> flags & FLAG_MINUS && !(format -> flags & FLAG_ZERO)))
//			pad_helper(padding, ' ', printed_chars);
//	}
//	else
//		(*printed_chars) += ft_putstr_fd(str, 1);
//	free(str);
//}
//
//
//void	pbonus_di(int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//	int		len;
//	int		padding;
//	char	*print_prefix;
//	int		total_width;
//
//	str = ft_printf_itoa(n);//1
//	len = ft_strlen(str);//1
//	print_prefix = prefix(n, format);//-
//	total_width = len + ft_strlen(print_prefix);//2
//	padding = hm_padding(total_width, format);//0
//	if (!(format -> flags & FLAG_MINUS))//yes
//	{
//		if (n < 0 || format -> flags & FLAG_PLUS)//yes
//		{
//			if (format -> flags & FLAG_ZERO)//no
//			{
//				(*printed_chars) += ft_putstr_fd(print_prefix, 1);
//				pad_helper(padding, '0', printed_chars);
//			}
//			else//yes
//			{
//				pad_helper(padding, ' ', printed_chars);//prints nothing
//				(*printed_chars) += ft_putstr_fd(print_prefix, 1);//prints -
//			}
//		}
//	}
//	(*printed_chars) += ft_putstr_fd(str, 1);//prints 1
//	if (format -> flags & FLAG_MINUS)
//		pad_helper(padding, ' ', printed_chars);
//	free(str);
//}

//void	pbonus_di(int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//	int		len;
//	int		padding;
//	char	*print_prefix;
//	int		total_width;
//
//	str = ft_printf_itoa(n);//14
//	len = ft_strlen(str);//2
//	print_prefix = prefix(n, format);//'-'
//	total_width = len + ft_strlen(print_prefix);//2+1 = 3
//	padding = hm_padding(total_width, format);// 1
//	if (!(format -> flags & FLAG_MINUS))//no
//	{
//		if (format -> flags & FLAG_ZERO && format -> precision < 0)
//			pad_helper(padding, '0', printed_chars);
//		else// if (!(format -> flags & FLAG_ZERO))
//			pad_helper(padding, ' ', printed_chars);
//	}
//	(*printed_chars) += ft_putstr_fd(print_prefix, 1);
//	(*printed_chars) += ft_putstr_fd(str, 1);
//	if (format -> flags & FLAG_MINUS)
//		pad_helper(padding, ' ', printed_chars);
//	free(str);
//}
//

//void	pbonus_u(unsigned int n, t_format *format, int *printed_chars)
//{
//	char	*str;
//	int		len;
//	int		padding;
//
//	str = ft_itoa(n);
//	len = ft_strlen(str);
//	padding = 0;
//	if (format -> width > len || format -> precision > len)
//	{
//		if (format -> width > len)
//		{
//			padding = format -> width - len;
//			if (format -> flags & FLAG_MINUS && format -> flags & FLAG_ZERO)
//				format -> flags = ~FLAG_ZERO;
//			else if (!(format -> flags & FLAG_MINUS) && !(format -> flags & FLAG_ZERO))
//				pad_helper(padding, ' ', printed_chars);
//		}
//		if (format -> precision > len)
//		{
//			padding = format -> precision - len;
//			format -> flags |= FLAG_ZERO;
//		}
//		if (format -> flags & FLAG_ZERO)
//			pad_helper(padding, '0', printed_chars);
//		(*printed_chars) += ft_putstr_fd(str, 1);
//		if ((format -> flags & FLAG_MINUS && !(format -> flags & FLAG_ZERO)))
//			pad_helper(padding, ' ', printed_chars);
//	}
//	else
//		(*printed_chars) += ft_putstr_fd(str, 1);
//	free(str);
//}

void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars)
{
	if (format -> flags & FLAG_HASH)
		(*printed_chars) += ft_putstr_fd("0x", 1);
	(*printed_chars) += ft_print_hex(n, upp);
}
