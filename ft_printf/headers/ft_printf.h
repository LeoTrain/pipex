/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 07:52:18 by leberton          #+#    #+#             */
/*   Updated: 2025/05/09 07:54:01 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int				ft_printf(const char *c, ...);
int				arg_to_str(const char *str);
int				arg_to_ptr(unsigned long long ptr);
int				arg_to_int(int d, int plus);
int				arg_to_hexa(unsigned int n, int uppercase);
unsigned int	arg_to_uint(unsigned int n);

#endif 
