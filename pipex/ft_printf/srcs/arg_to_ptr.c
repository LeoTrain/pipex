/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:52:55 by leberton          #+#    #+#             */
/*   Updated: 2025/05/08 23:58:31 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	length(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	uint_to_hexa(unsigned long long n)
{
	if (n >= 16)
	{
		uint_to_hexa(n / 16);
		uint_to_hexa(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar_fd(n - 10 + 'a', 1);
		else
			ft_putchar_fd(n + '0', 1);
	}
}

int	arg_to_ptr(unsigned long long n)
{
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	uint_to_hexa(n);
	return (length(n) + 2);
}
