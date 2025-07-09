/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:09:31 by leberton          #+#    #+#             */
/*   Updated: 2025/04/28 06:26:47 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	num;

	num = n;
	sign = 1;
	if (num < 0)
	{
		num = -num;
		sign = -1;
	}
	len = ft_numlen(num) + (sign == -1);
	str = (char *)ft_calloc(len + 1, sizeof(char *));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign == -1)
		str[0] = '-';
	while (num > 0)
	{
		str[--len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
