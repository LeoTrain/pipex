/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:04:53 by leberton          #+#    #+#             */
/*   Updated: 2025/05/09 00:29:32 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	putch(int c)
{
	char	a;

	a = (char)c;
	return (write(1, &a, 1));
}

static int	execute_format(va_list *args, const char *c)
{
	if (*c == '%')
		return (write(1, "%", 1));
	else if (*c == 'c')
		return (putch(va_arg(*args, int)));
	else if (*c == 's')
		return (arg_to_str(va_arg(*args, char *)));
	else if (*c == 'p')
		return (arg_to_ptr(va_arg(*args, unsigned long long)));
	else if (*c == 'd' || *c == 'i')
		return (arg_to_int(va_arg(*args, int), 0));
	else if (*c == 'u')
		return (arg_to_uint(va_arg(*args, unsigned int)));
	else if (*c == 'x' || *c == 'X')
		return (arg_to_hexa(va_arg(*args, int), *c == 'X'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	if (s == NULL)
		return (-1);
	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			len += execute_format(&args, ++s);
		else
			len += putch(*s);
		s++;
	}
	va_end(args);
	return (len);
}
