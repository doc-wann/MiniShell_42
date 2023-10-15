/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:45:35 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 23:24:42 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	token_lst_add_back(t_token_lst **token_lst, t_token_lst *token)
{
	t_token_lst	*back;

	if (*token_lst == NULL)
	{
		*token_lst = token;
		return ;
	}
	back = *token_lst;
	while (back->next)
		back = back->next;
	back->next = token;
}

t_token_lst	*token_lst_new(char *value, int token)
{
	t_token_lst	*new;

	new = (t_token_lst *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->token = token;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	go_to_token_lst(t_data *data, char *value, int index, int token)
{
	char			*word;
	t_token_lst		*new_token;

	new_token = NULL;
	if (data->token_lst_nb == 1)
	{
		word = ft_substr(value, index, check_arg_cmd_size(value, index));
		if (!word)
			exit_minishell (data);
		new_token = token_lst_new(word, token);
	}
	else if (data->token_lst_nb == 2)
		new_token = token_lst_new(value, token);
	token_lst_add_back(&data->token_lst, new_token);
}
