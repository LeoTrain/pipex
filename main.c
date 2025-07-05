/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:21:10 by leberton          #+#    #+#             */
/*   Updated: 2025/07/05 13:34:34 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

void	ft_puterror(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char *ft_strjoin_free(char *s1, const char *s2)
{
	char *res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

void	ft_free_split(char **tab)
{
	int i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path_env = envp[i] + 5;
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin_free(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2], fd1, fd2;
	pid_t	pid1, pid2;

	if (argc != 5)
		ft_puterror("You must have exactly 4 arguments.");

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		ft_puterror("open infile");
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
		ft_puterror("open outfile");
	if (pipe(fd) == -1)
		ft_puterror("pipe");

	pid1 = fork();
	if (pid1 < 0)
		ft_puterror("fork");
	else if (pid1 == 0)
	{
		if (dup2(fd1, STDIN_FILENO) == -1)
			ft_puterror("dup2 infile");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_puterror("dup2 pipe write");
		close(fd[0]); close(fd[1]); close(fd1); close(fd2);
		char **cmd_args = ft_split(argv[2], ' ');
		char *cmd_path = get_cmd_path(cmd_args[0], envp);
		if (!cmd_path)
			ft_puterror("command not found cmd1");
		if (execve(cmd_path, cmd_args, envp) == -1)
			ft_puterror("execve cmd1");
	}

	pid2 = fork();
	if (pid2 < 0)
		ft_puterror("fork");
	else if (pid2 == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_puterror("dup2 pipe read");
		if (dup2(fd2, STDOUT_FILENO) == -1)
			ft_puterror("dup2 outfile");
		close(fd[0]); close(fd[1]); close(fd1); close(fd2);
		char **cmd_args = ft_split(argv[3], ' ');
		char *cmd_path = get_cmd_path(cmd_args[0], envp);
		if (!cmd_path)
			ft_puterror("command not found cmd2");
		if (execve(cmd_path, cmd_args, envp) == -1)
			ft_puterror("execve cmd2");
	}

	close(fd[0]); close(fd[1]); close(fd1); close(fd2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

