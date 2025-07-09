/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:32:35 by leberton          #+#    #+#             */
/*   Updated: 2025/07/05 14:07:42 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd[2];
	int		fd1;
	int		fd2;
	char	**argv;
	char	**envp;
}	t_pipex;

void	ft_puterror(const char *str, int exit_code);
char	*ft_strjoin_free(char *s1, const char *s2);
void	ft_free_split(char **tab);
void	exec_cmd1(int fd1, int *fd, char **argv, char **envp);
void	exec_cmd2(int fd2, int *fd, char **argv, char **envp);
char	*get_cmd_path(char *cmd, char **envp);

#endif
