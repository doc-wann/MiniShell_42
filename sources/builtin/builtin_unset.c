#include "../includes/minishell.h"

char **lst_move(char **lst,int tomove);

void	builtin_unset(char **cmd, t_data *data)
{
	int i;

	i = 0;

	cmd =  ft_varfetch(cmd, data);
	//THIS IS MERELY A "JUST TO MAKE IT WORK" SOLUTION
	cmd[0] += 5;
	cmd[0] = ft_strtrim(cmd[0], " ");

	while(i < ft_lstlen(data->env))
	{
		if(ft_strcmp(cmd[0], ft_split(data->env[i], '=')[0]) == 0)
		{
			data->env = lst_move(data->env, i);
			return ;
		}
		i++;
	}
	ft_printf("No matches were found sadpeepo\n");
	return ;
}

char **lst_move(char **lst, int tomove)
{
	lst[tomove] = lst[0];
	lst++;
	ft_printf("\n\n\n\n\n");
	return (lst);
}
