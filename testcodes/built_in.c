/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2022/12/29 13:19:11 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../Project_Dir/includes/data.h>

void	ft_echo(char **cmd_vector, t_list envp_list)
{
	int	i;
	int	new_line_flag;

	if (ft_strcmp(cmd_vector[1], "-n"))
	{
		new_line_flag = 0;
		i = 2;
	}
	else
	{
		new_line_flag = 1;
		i = 1;
	}
	while (cmd_vector[i])
	{
		ft_printf("%s", cmd_vector[i]);
		i++;
	}
	if (new_line_flag == 1)
		ft_printf("\n");
}

void	ft_cd(char **cmd_vector, t_list *envp_list)
{
	t_envp	*node_p;

	node_p = find_node_type_p(envp_list, "PWD");
	node_p->content-> =


}

void	ft_pwd(char **cmd_vector, t_list envp_list)
{
	char	*pwd;


	pwd = envp_find(data, "PWD");
	ft_printf("%s\n", pwd);
}

void	ft_export(char **cmd_vector, t_list envp_list)
{
	int		equal_i;
	int		cmd_i;
	char	**envp_arr;

	cmd_i = 1;
	while (cmd_vector[cmd_i])
	{
		equal_i = find_chr(cmd_vector[cmd_i], '=');
		envp_add(envp_list, envp_arr[0]);
		cmd_i++;
	}
}

void	ft_unset(char **cmd_vector, t_list envp_list)
{

}

void	ft_env(char **cmd_vector, t_list envp_list)
{

}

void	ft_exit(char **cmd_vector, t_list envp_list)
{

}
