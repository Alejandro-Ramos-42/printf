/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:45:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 17:40:19 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

#define FLAG_MINUS	1
#define FLAG_ZERO	2
#define FLAG_HASH	4
#define FLAG_PLUS	8
#define FLAG_SPACE	16

typedef struct s_format
{
	int		flags;
	int		width;
	int		precision;
	char	f_specifier;
}	t_format;

int		ft_printf(const char *str, ...);
void	parse_flags(const char **str, t_format *format);
void	parse_width(const char **str, t_format *format, va_list args);
void	parse_precision(const char **str, t_format *format, va_list args);
void	parse_specifier(const char **str, t_format *format);
void	apply_specifier(t_format *format, va_list args, int *printed_chars);
void	print_padding(const char *str, t_format *format, int *printed_chars);
void	print_i_formatted(int n, t_format *format, int *printed_chars);
void	print_u_formatted(unsigned int n, t_format *format, int *printed_chars);
void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars);


