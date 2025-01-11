/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:45:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/11 12:25:46 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

#define FLAG_MINUS	1//00000001
#define FLAG_ZERO	2//00000010
#define FLAG_HASH	4//00000100
#define FLAG_PLUS	8//00001000
#define FLAG_SPACE	16//0010000

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
void	pbonus_s(const char *str, t_format *format, va_list args, int *printed_chars);
void	pbonus_c(char c, t_format *format, int *printed_chars);
void	pbonus_di(int n, t_format *format, int *printed_chars);
char	*pbonus_di_helper(t_format *format, int len);
void	pbonus_u(unsigned int n, t_format *format, int *printed_chars);
void	print_hx(unsigned int n, t_format *format, int upp, int *printed_chars);


