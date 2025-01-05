/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:52:49 by aramos            #+#    #+#             */
/*   Updated: 2024/12/14 14:05:09 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*maxint_n(void);

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*result;
	int		len;

	if (n == -2147483648)
		return (maxint_n());
	num = n;
	len = num_len(n);
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		num = -num;
	if (n == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

char	*maxint_n(void)
{
	char	*result;

	result = (char *) malloc(12 * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}
//
//int	main(void)
//{
//	int	number;
//
//	number = -2147483648;
//	printf("%s\n", ft_itoa(number));
//	return (0);
//}
