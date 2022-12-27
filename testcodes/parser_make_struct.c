/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:31:55 by tyi               #+#    #+#             */
/*   Updated: 2022/12/26 22:30:31 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_list	infile_lst;
	t_list	outfile_lst;
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

int	main()
{
	t_list	token_list;
	
	token_list = make_token_list();	
	execcute(make_proc_data_arr(&token_list));
}