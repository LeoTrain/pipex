/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:59:50 by leberton          #+#    #+#             */
/*   Updated: 2025/07/05 14:02:09 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_puterror(const char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}
