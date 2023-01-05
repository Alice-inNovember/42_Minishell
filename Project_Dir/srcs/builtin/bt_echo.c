/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:26 by tyi               #+#    #+#             */
/*   Updated: 2023/01/05 19:22:46 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	check_word_cnt(char **cmd_vector)
{
	int	i;

	i = 0;
	while (cmd_vector[i])
		i++;
	return (i);
}

void	print_word(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{	
		if (!ft_strncmp(word + i, "$?", 2))
		{
			printf("%d", g_last_exit_status);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(word[i], 1);
			i++;
		}
	}
}

int	is_proper_opt(char *word, char opt_chr)
{
	int	i;

	i = 1;
	if (word[0] != '-' || ft_strlen(word) < 2)
		return (EX_SUCCESS);
	while (word[i])
	{
		if (word[i] != opt_chr)
			return (EX_SUCCESS);
		i++;
	}
	return (EX_BT_FAIL);
}

int	bt_echo(char **cmd_vector, t_list *envp_list)
{
	int		i;
	int		new_line_flag;

	(void)envp_list;
	new_line_flag = 1;
	i = 1;
	while (cmd_vector[i] && is_proper_opt(cmd_vector[i], 'n'))
	{
		new_line_flag = 0;
		i++;
	}
	while (cmd_vector[i])
	{
		print_word(cmd_vector[i]);
		if (!cmd_vector[i + 1])
			break ;
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line_flag == 1)
		printf("\n");
	return (EX_SUCCESS);
}
