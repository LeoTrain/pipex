/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:50:40 by leberton          #+#    #+#             */
/*   Updated: 2025/05/08 23:52:34 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	arg_to_int(int n, int plus)
{
	size_t		len;
	char		*num;

	if (n == 0)
		return (write(1, "0", 1));
	num = ft_itoa(n);
	len = ft_strlen(num);
	if (plus && n >= 0)
		len += write(1, "+", 1);
	write(1, num, ft_strlen(num));
	free(num);
	return (len);
}
