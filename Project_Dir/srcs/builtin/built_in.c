/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:49 by tyi               #+#    #+#             */
/*   Updated: 2023/01/05 23:11:39 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/builtin.h"

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	char	**vec;
// 	t_list	envp_list;

// 	((void) ac, (void) av);
// 	envp_init(&envp_list, envp);
// 	while (1)
// 	{
// 		line = readline("minishell > ");
// 		add_history(line);
// 		vec = ft_split(line, ' ');
// 		if (!ft_strcmp(vec[0], "echo"))
// 			bt_echo(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "pwd"))
// 			bt_pwd(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "unset"))
// 			bt_unset(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "cd"))
// 			bt_cd(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "env"))
// 			bt_env(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "export"))
// 			bt_export(vec, &envp_list);
// 		else if (!ft_strcmp(vec[0], "exit"))
// 			bt_exit(vec, &envp_list);
// 		else
// 			printf("no_command\n");
// 	}
// 	return (EX_SUCCESS);
// }
