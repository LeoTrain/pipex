/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:56:49 by leberton          #+#    #+#             */
/*   Updated: 2025/07/05 13:58:06 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	setup_and_exec(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(cmd_args[0], envp);
	// FILE *file_ptr = fopen("test_print.txt", "a");
	// fprintf(file_ptr, "%s\n", cmd);
	// for (int i = 0; cmd_args[i]; i++)
	//     fprintf(file_ptr, "%s\n", cmd_args[i]);
	// fclose(file_ptr);
	if (!cmd_path)
	{
		ft_free_split(cmd_args);
		ft_puterror("command not found", 1);
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
		ft_puterror("execve failed", 1);
}

void	exec_cmd1(int fd1, int *fd, char **argv, char **envp)
{
	if (dup2(fd1, STDIN_FILENO) == -1)
	    ft_puterror("dup2 infile", 1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_puterror("dup2 pipe write", 1);
	close(fd[0]);
	close(fd[1]);
	close(fd1);
	setup_and_exec(argv[2], envp);
}

void	exec_cmd2(int fd2, int *fd, char **argv, char **envp)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_puterror("dup2 pipe read", 1);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		ft_puterror("dup2 outfile", 1);
	close(fd[0]);
	close(fd[1]);
	close(fd2);
	// FILE *file_ptr = fopen("test_print.txt", "a");
	// fprintf(file_ptr, "%s\n", argv[3]);
	// fclose(file_ptr);
	setup_and_exec(argv[3], envp);
}
