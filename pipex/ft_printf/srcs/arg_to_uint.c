/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:59:56 by leberton          #+#    #+#             */
/*   Updated: 2025/05/09 00:04:38 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	length(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = length(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (n != 0)
	{
		str[len-- - 1] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

unsigned int	arg_to_uint(unsigned int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	str = ft_uitoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
