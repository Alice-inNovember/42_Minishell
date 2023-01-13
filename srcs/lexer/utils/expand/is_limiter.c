/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_limiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:07:00 by tyi          #+#    #+#             */
/*   Updated: 2023/01/08 22:53:37 by tyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

int	is_limiter(t_list *token_list)
{
	t_token	*last_token;

	last_token = list_peek_last_content(token_list);
	if (last_token != NULL && last_token->type == T_DLESS)
		return (1);
	else
		return (0);
}
