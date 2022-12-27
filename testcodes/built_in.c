/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2022/12/27 19:59:33 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_cd(char **cmd_vector, t_list envp_list)
{

}

void	ft_pwd(char **cmd_vector, t_list envp_list)
{

}

void	ft_export(char **cmd_vector, t_list envp_list)
{

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
