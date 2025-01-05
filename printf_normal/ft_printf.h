/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:45:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/05 15:00:15 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct s_format
{
	char	f_specifier;
}	t_format;

int		ft_printf(const char *str, ...);
void	parse_specifier(const char **str, t_format *format);
void	apply_specifier(t_format *format, va_list *args, int *printed_chars);
void	print_i_formatted(int n, t_format *format, int *printed_chars);
void	print_u_formatted(unsigned int n, t_format *format, int *printed_chars);
void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars);
