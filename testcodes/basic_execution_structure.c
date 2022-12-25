/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_execution_structure.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:50:01 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/25 22:50:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"

typedef struct	s_redir_lst
{
	int	type;
	int	in;
	int	out;
	...
}	t_redir_lst;

typedef struct s_proc
{
	pid_t		pid;
	int			stat;
	char		*cmd;
	t_redir_lst	*redir_out;
	t_redir_lst	*redir_in;
	...
}	t_proc;

typedef struct s_info
{
	t_proc	*proc; // cmd 개수만큼 할당
	int		cmd_num;
	...
}	t_info;

void	execute_cmd(t_proc proc)
{
	if (proc.built_in == TRUE)
	{
		execute_built_in(proc);
		exit();
	}
	else
		execve(proc.cmd_path, proc.cmd_argv, proc_cmd_envp);
}

void	execute(t_info *info)
{
	int		i;
	pid_t	pid;

	if (info->cmd_num == 1 && info->proc[0].built_in == TRUE)
	{
		execute_single_built_in(info);
		return ;
	}
	i = 0;
	while (i < info->cmd_num)
	{
		if (i < info->cmd_num - 1) // 프로세스 수 보다 하나 적게 파이프 생성
			pipe(info->proc[i].fd); // info->proc[i] 안에 int fd[2]
		pid = fork();
		if (pid != 0) 
			execute_cmd(info->proc[i]);
		i++;
	}
	i = 0;
	while (i < info->cmd_num) // 커맨드 실행 프로세스 종료까지 대기 및 종료 상태 받기
	{
		waitpid(info->proc[i].pid, &info->proc[i].stat, NULL);
		i++;
	}
}

void	parse_and_execute(void)
{
	t_info	*info;
	char	*str;

	init_info(info); // 구조체 초기화
	while (1)
	{
		str = readline("minishell> ");
		if (!ft_strcmp(str, "exit"))
			return ;
		parse(str, info);
		excute(info);
		free(str);
	}
}

int	main(int argc, char **argv, char **envp)
{
	check_argument(); // if argc > 1 : 종료 및 에러메세지($> bash script.sh 와 같은 경우 처리)
	init_and_parse_envp(); // 초기화(OLDPWD 등) 및 key : value 로 분리
	handle_signal(); // 시그널 핸들러
	parse_and_execute();
	return (0);
}
