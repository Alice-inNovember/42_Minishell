/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file_using_mktemp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:25 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/05 17:18:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	execve_cmd(t_data *data, int fd[2], char *cmd_path, char **cmd_argv)
{
	char	**envp;

	envp = envp2arr(&data->envp_list);
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execve(cmd_path, cmd_argv, envp);
}

static char	*read_fname_from_pipe(pid_t pid, int fd[2])
{
	char	*fname;
	int		last_index;
	int		wstatus;

	waitpid(pid, &wstatus, 0);
	if (wexitstatus(wstatus) != 0)
	{
		ft_putendl_fd("mktemp failure", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fname = get_next_line(fd[READ_END]);
	last_index = ft_strlen(fname) - 1;
	if (fname[last_index] == '\n')
		fname[last_index] = '\0';
	return (fname);
}

char	*make_file_using_mktemp(t_data *data, \
										char *mktemp_path, char **mktemp_argv)
{
	char	*fname;
	int		fd[2];
	int		ret;
	pid_t	pid;

	ret = pipe(fd);
	pid = fork();
	if (pid == 0)
		execve_cmd(data, fd, mktemp_path, mktemp_argv);
	close(fd[WRITE_END]);
	fname = read_fname_from_pipe(pid, fd);
	return (fname);
}
