#include "../includes/minishell.h"

void	minishell_loop(t_data *data)
{
	while (data->exit == 0)
	{
		data->read_line = readline("minishell> ");
		if (data->read_line[0] != 0)
			add_history(data->read_line);
		cmd_lst_create(data);
		cmd_execv(data);
	}
}
