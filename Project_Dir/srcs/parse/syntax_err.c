/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:29 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/29 15:33:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// data에 int	syntax_err_flag;

void	del_s_token(void *token)
{
	ft_free(&(t_token *)token);
}

// t_proc_data {
//t_list redir_lst;
//t_list cmd_lst;
//}

void	del_s_redir(void *redir)
{
	ft_free(&(t_redir *)redir);
}

void	del_proc_data(t_proc_data *proc_data)
{
	lst_clear(&proc_data->cmd_lst, del_s_cmd);
	lst_clear(&proc_data->redir_lst, del_s_redir);
}

void	syntax_err(t_data *data)
{
	data->syntax_err_flag = 1;
	lst_clear(&data->token_lst, del_s_token);
	lst_clear(&data->proc_data_lst, del_proc_data);
	printf("error : syntax error\n");
}
