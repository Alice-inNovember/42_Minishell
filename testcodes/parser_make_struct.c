/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:31:55 by tyi               #+#    #+#             */
/*   Updated: 2022/12/27 15:59:14 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum e_type
{
	WORD,
	PIPE,
	LESS,
	GREAT,
	DLESS,
	DGREAT
}	t_type;

// define token as node
typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

typedef struct s_command
{
	char	**cmd_vector;
	t_list	*infile_lst;
	t_list	*outfile_lst;
}	t_command;

typedef struct s_list
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_list;


typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_proc_data
{
	char	**cmd_arr;
	t_list	*infile_redir_list;
	t_list	*outfile_redir_list;

}	 t_proc_data;

t_proc_data make_cmd_arr(t_list	*token_list, t_token last_p)
{
	while (token->list = last_p)
	{
	 
	}
	return ()
}

t_command	*make_proc_data_arr(t_list *token_list)
{
	int		i;
	t_token	*last_p;
	t_token *redir;
	t_proc_data *proc_data_arr;

	proc_data_arr = malloc(sizeof(t_proc_data) * check_pipe_cnt(token_list) + 1);
	i = 0;
	while (1)
	{
		if (find_pipe(token_list) != -1)
		{
			last_p = find_pipe(token_list);
			while (find_redir(token_list, last_p) != -1)
			{
				redir = find_redir(token_list, last_p);
				proc_data_arr[i]->value = redir->next->value;
				proc_data_arr[i]->type = redir->type;
				list_delete(redir);
				list_delete(redir->next);
			}
			proc_data_arr[i] = make_cmd_arr(token_list, last_p);
			list_delete(last_p);
		}	
		else
		{
			last_p = token_list->tail;
			while (find_redir(token_list, last_p) != -1)
			{
				redir = find_redir(token_list, last_p);
				proc_data_arr[i]->value = redir->next->value;
				proc_data_arr[i]->type = redir->type;
				list_delete(redir);
				list_delete(redir->next);
			}
			proc_data_arr[i] = make_cmd_arr(token_list, last_p);
			list_clear(token_list);
			break;
		}		
		i++;
	}
	proc_data_arr[i] = 0;
	return (proc_data_arr);
}

void	print_redir_list(t_list *list)
{
	t_node	*cur_node;
	t_token	*token;

	cur_node = list->head->next;
	while (cur_node->next != NULL)
	{
		token = cur_node->content;
		printf("<token>\n");
		printf("token type = ");
		print_enum(token->type);
		printf("\ntoken value = %s\n\n", token->value);
		cur_node = cur_node->next;
	}
}

void	print_proc_data_arr(t_proc_data	*proc_data_arr)
{
	int	i;
	int	j;

	i = 0;
	while (proc_data_arr[i].cmd_arr)
	{
		printf("<cmd_arr>\n");
		
		j = 0;
		while (proc_data_arr[i].cmd_arr[j])
		{
			printf("%d : %s \n", j, proc_data_arr[i].cmd_arr[j]);
			j++;
		}

		printf("-----------");

		printf("infile list = ");
		print_redir_list(proc_data_arr[i].infile_redir_list);
		
		printf("outfile list = ");		
		print_redir_list(proc_data_arr[i].outfile_redir_list);
		i++;
	}
}

void	make_example_proc_data(t_proc_data *proc_data_arr)
{
	proc_data_arr[0].cmd_arr = ;
	proc_data_arr[0].infile_redir_list = ;
	proc_data_arr[0].outfile_redir_list = ;
	proc_data_arr[1].cmd_arr = ;
	proc_data_arr[1].infile_redir_list = ;
	proc_data_arr[1].outfile_redir_list = ;

}

void	parse_and_execute(void)
{
	t_list	*token_list;
	t_proc_data	proc_data_arr[3];
	char	*str;

	// init_info(info); // 구조체 초기화
	while (1)
	{
		str = readline("minishell> ");
		if (!ft_strcmp(str, "exit"))
			return ;
		token_list = lexer(str, info);
		proc_data_arr = parser(token_list);
		make_example_proc_data(proc_data_arr);
		print_proc_data_arr(proc_data_arr);
		// excute(proc_data_arr);
		// free(str);
	}
}

int	main(int argc, char **argv, char **envp)
{
	check_argument(); // if argc > 1 : 종료 및 에러메세지($> bash script.sh 와 같은 경우 처리)
	init_and_parse_envp(); // 초기화(OLDPWD 등) 및 key : value 로 분리
	handle_signal(); // 시그널 핸들러
	parse_and_execute();
	return (0);
}s