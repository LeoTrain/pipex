/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:52:47 by leberton          #+#    #+#             */
/*   Updated: 2025/05/09 00:20:12 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	length(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	uint_to_hexa(unsigned int n, int uppercase)
{
	if (n >= 16)
	{
		uint_to_hexa(n / 16, uppercase);
		uint_to_hexa(n % 16, uppercase);
	}
	else
	{
		if (n > 9)
		{
			if (!uppercase)
				ft_putchar_fd((n - 10 + 'a'), 1);
			else
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
		else
			ft_putchar_fd((n + '0'), 1);
	}
}

int	arg_to_hexa(unsigned int n, int uppercase)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	uint_to_hexa(n, uppercase);
	return (length(n) + len);
}
