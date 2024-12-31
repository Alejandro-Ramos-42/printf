/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:45:33 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 14:46:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FLAG_MINUS	1
#define FLAG_ZERO	2
#define FLAG_HASH	4
#define FLAG_PLUS	8
#define FLAG_SPACE	16

#define SPEC_C		1
#define SPEC_S		2
#define SPEC_P		4
#define SPEC_D		8
#define SPEC_I		16
#define SPEC_U		32
#define SPEC_LX		64
#define SPEC_X		128

typedef struct s_format {
	int	flags;
	int	width;
	int	precision;
	int	f_specifier;
} t_format;

int	ft_printf(const char *, ...);
void	parse_flags(const char **str, t_format *format);
void	parse_width(const char **str, t_format *format, va_list args);
void	parse_specifier(t_format *format, char c);
void	apply_specifier(t_format *format, va_list args);
