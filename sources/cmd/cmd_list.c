/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:29 by nsutter           #+#    #+#             */
/*   Updated: 2023/09/30 22:43:27 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/****************************************************************************/
/* SPLIT													    			*/
/****************************************************************************/

static int	ft_nb_split(char const *s, char c)
{
	unsigned int	x;
	int				n;

	x = 0;
	n = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
			n++;
		while (s[x] != c && s[x] != '\0')
			x++;
	}
	return (n);
}

static char	*ft_str_split(char const *s, int x, int size)
{
	char	*str;
	int		z;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	z = 0;
	while (z < size)
	{
		str[z] = s[x];
		z++;
		x++;
	}
	str[z] = '\0';
	return (str);
}

static char	**ft_dst_split(char **dst, t_data *data, char c)
{
	char	*s;
	int		x;
	int		y;
	int		size;

	s = data->read_line;
	x = 0;
	y = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
		{
			size = 0;
			while (s[x + size] != c && s[x + size] != '\0')
				size++;
			dst[y] = ft_str_split(s, x, size);
			x = x + size;
			y++;
		}
	}
	dst[y] = NULL;
	return (dst);
}

char	**ft_split_test(t_data *data, char c)
{
	char	**dst;

	if (data->read_line == 0)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_nb_split(data->read_line, c) + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_dst_split(dst, data, c));
}

/****************************************************************************/
/* cmd_lst_create															*/
/****************************************************************************/

void	lstadd_back_cmd(t_cmd_lst **cmd_lst, t_cmd_lst *cmd)
{
	t_cmd_lst	*back;

	if (*cmd_lst == NULL)
	{
		*cmd_lst = cmd;
		return ;
	}
	back = *cmd_lst;
	while (back->next)
		back = back->next;
	back->next = cmd;
}

t_cmd_lst	*lstnew_cmd(t_data *data, char *cmd)
{
	t_cmd_lst	*new;

	new = (t_cmd_lst *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->process = ft_split(cmd, ' ');
	new->cmd = new->process[0];
	if (data->nb_execv > 0)
		new->parser = "|";
	else
		new->parser = NULL;
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	cmd_lst_create(t_data *data)
{
	t_cmd_lst	**cmd_lst;
	t_cmd_lst	*new;
	char		**arg;
//	char		**arg_test;
	int			i;

	cmd_lst = (t_cmd_lst **)malloc(sizeof(t_cmd_lst));
	if (cmd_lst == NULL)
		printf("error");
	*cmd_lst = NULL;
	arg = ft_split(data->read_line, '|');
/*	arg_test = ft_split_test(data, '|');
	i = 0;
	while (arg_test[i])
	{
		arg_test[i] = ft_strtrim(arg_test[i], " \n\t");
		printf("arg_test : %s\n", arg_test[i]);
		i++;
	}*/
	i = 0;
	data->nb_execv = 0;
	while (arg[i])
	{
		arg[i] = ft_strtrim(arg[i], " \n\t");
		new = lstnew_cmd(data, arg[i]);
		lstadd_back_cmd(cmd_lst, new);
		data->nb_execv = data->nb_execv + 1;
		i++;
	}
	data->cmd_lst = *cmd_lst;
/*	while (data->cmd_lst)
	{
		printf("parser     : %s\n", data->cmd_lst->parser);
		printf("cmd        : %s\n", data->cmd_lst->cmd);
		printf("process[0] : %s\n", data->cmd_lst->process[0]);
		printf("process[1] : %s\n", data->cmd_lst->process[1]);
		printf("process[2] : %s\n", data->cmd_lst->process[2]);
		data->cmd_lst = data->cmd_lst->next;
	}*/
	return (0);
}
