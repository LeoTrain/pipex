/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:21:10 by leberton          #+#    #+#             */
/*   Updated: 2025/07/05 14:06:58 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	setup_fds(t_pipex *p)
{
	p->fd1 = open(p->argv[1], O_RDONLY);
	if (p->fd1 < 0)
		ft_puterror("open infile");
	p->fd2 = open(p->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->fd2 < 0)
		ft_puterror("open outfile");
	if (pipe(p->fd) == -1)
		ft_puterror("pipe");
	return (0);
}

void	exec_forks(t_pipex *p)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		ft_puterror("fork");
	else if (pid1 == 0)
		exec_cmd1(p->fd1, p->fd, p->argv, p->envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_puterror("fork");
	else if (pid2 == 0)
		exec_cmd2(p->fd2, p->fd, p->argv, p->envp);
	close(p->fd[0]);
	close(p->fd[1]);
	close(p->fd1);
	close(p->fd2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc != 5)
		ft_puterror("You must have exactly 4 arguments.");
	p.argv = argv;
	p.envp = envp;
	setup_fds(&p);
	exec_forks(&p);
	return (0);
}
