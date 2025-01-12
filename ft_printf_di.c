/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:53:49 by aramos            #+#    #+#             */
/*   Updated: 2025/01/12 15:58:08 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void pbonus_di(int n, t_format *format, int *printed_chars)
{
    char *str;
    int len, padding;
    int prefix_len = 0;

    str = ft_itoa(n);  // Convert number to string
    len = ft_strlen(str);  // Length of the number
    padding = 0;

    // Handle prefix (sign)
    if (n < 0 || format->flags & FLAG_PLUS || format->flags & FLAG_SPACE) {
        if (n < 0) {
            prefix_len = 1;
            str++; // Skip the '-' sign for the rest of the number
        } else if (format->flags & FLAG_PLUS) {
            prefix_len = 1;
        } else if (format->flags & FLAG_SPACE) {
            prefix_len = 1;
        }
    }

    // Calculate padding and handle width
    if (format->width > len + prefix_len) {
        padding = format->width - (len + prefix_len);
        if (format->flags & FLAG_MINUS) {
            pad_helper(padding, ' ', printed_chars);
            padding = 0;
        } else if (format->flags & FLAG_ZERO) {
            pad_helper(padding, '0', printed_chars);
            padding = 0;
        } else {
            pad_helper(padding, ' ', printed_chars);
        }
    }

    // Print the sign (prefix)
    if (n < 0) {
        (*printed_chars) += ft_putchar_fd('-', 1);
    } else if (format->flags & FLAG_PLUS) {
        (*printed_chars) += ft_putchar_fd('+', 1);
    } else if (format->flags & FLAG_SPACE) {
        (*printed_chars) += ft_putchar_fd(' ', 1);
    }

    // Print the number with precision and zero-padding
    if (format->precision > len) {
        pad_helper(format->precision - len, '0', printed_chars);
    }

    (*printed_chars) += ft_putstr_fd(str, 1);  // Print the number

    // Handle left padding if necessary (for FLAG_MINUS)
    if (format->flags & FLAG_MINUS) {
        pad_helper(padding, ' ', printed_chars);
    }

    free(str);
}
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
