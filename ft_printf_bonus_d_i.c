/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_d_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:00:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/15 19:35:04 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	pd(int n, int len, t_format *format, int *printed_chars);
static void	pad_helper(int padding, int *printed_chars, t_format *format);
static int	append_0(char **str, t_format *format);
static char	*prefix(int n, t_format *format);

//%d and %i specifiers
void	pbonus_di(int n, t_format *format, int *printed_chars)
{
	char	*str;
	int		len;
	int		padding;

	str = ft_printf_itoa(n);//returns possitive number in a string form
	len = append_0(&str, format);//the length with 0s pad if needed
	padding = pd(n, len, format, printed_chars);//prints prefix if needed and sets width pad amount
	if (!(format -> flags & FLAG_MINUS))//if not - flag
		pad_helper(padding, printed_chars, format);//prints pad
	(*printed_chars) += ft_putstr_fd(str, 1);//prints number
	format -> pad = ' ';//sets pad
	if (format -> flags & FLAG_MINUS)//if flag - is active
		pad_helper(padding, printed_chars, format);//prints pad
	free(str);
}

static int	append_0(char **str, t_format *format)
{
	int		len;
	int		difference;
	char	*new_str;

	if (!str || !*str || !format)
		return (0);
	len = ft_strlen(*str);
	if ((format -> precision) > len)
	{
		difference = (format -> precision) - len;
		new_str = malloc ((difference + len + 1) * sizeof(char));
		if (!new_str)
			return (0);
		ft_memset(new_str, '0', difference);
		ft_strlcpy(new_str + difference, *str, (difference + len + 1));
		free(*str);
		*str = new_str;
		len += difference;
	}
	return (len);
}

static int	pd(int n, int len, t_format *format, int *printed_chars)
{
	int		padding;

	padding = 0;

	if (n < 0 || format->flags & FLAG_PLUS || format->flags & FLAG_SPACE)//if sufix needed
	{
		if (format -> flags & FLAG_ZERO)//if need to print sufix before padding
		{
			(*printed_chars) += ft_putstr_fd(prefix(n, format), 1);//print it
			format -> pad = '0';//change char to pad with to '0'
		}
		(len)++;//add 1 to lenght no matter if '0' is on or not
	}
	if (format -> width > len)//if need to pad  (takes in consideration the suffix)
		padding = (format -> width) - len;//sets the pad amount
	return (padding);

}

static char	*prefix(int n, t_format *format)
{
	if (n < 0)
		return ("-");
	if (format -> flags & FLAG_PLUS)
		return ("+");
	if (format -> flags & FLAG_SPACE)
		return (" ");
	return ("");
}

static void	pad_helper(int padding, int *printed_chars, t_format *format)
{
	while (padding--)
		(*printed_chars) += ft_putchar_fd(format -> pad, 1);
}
