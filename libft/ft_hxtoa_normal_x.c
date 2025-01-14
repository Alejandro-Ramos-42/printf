/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxtoa_normal_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alex.qsc2@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:42:10 by aramos            #+#    #+#             */
/*   Updated: 2025/01/14 11:39:09 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	x_to_alpha_normal_x(char *c);

int	get_len_normal_x(unsigned num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_hxtoa_normal_x(unsigned long n, int upp)
{
	unsigned long	num;
	char			*num_in_hex;
	char			*lookup_array;
	int				len;

	num = (unsigned long)n;
	len = 0;
	if (n == 0)
		len = 1;
	else
		len = get_len_normal_x(num);
	num_in_hex = malloc((len + 1) * sizeof (char));
	if (!num_in_hex)
		return (NULL);
	lookup_array = "0123456789abcdef";
	num_in_hex[len] = '\0';
	while (len > 0)
	{
		num_in_hex[--len] = lookup_array[num % 16];
		num /= 16;
	}
	if (upp == 1)
		x_to_alpha_normal_x(num_in_hex);
	return (num_in_hex);
}

static void	x_to_alpha_normal_x(char *c)
{
	while (*c)
	{
		*c = (char)ft_toupper(*c);
		c++;
	}
}

int	ft_print_hex_normal_x(unsigned long number, int upp)
{
	char			*num_hex;
	int				chars_printed;

	num_hex = ft_hxtoa_normal_x(number, upp);
	chars_printed = ft_putstr_fd(num_hex, 1);
	free(num_hex);
	return (chars_printed);
}
