#include "../includes/minishell.h"

void	minishell_loop(t_data *data)
{
	while (data->exit == 0)
	{
		data->read_line = readline("minishell> ");

		if (data->read_line[0] != 0)
			add_history(data->read_line);
//		if (!cmd_create_list(t_data *data));
//			error;
//		else
		cmd_execv(data);
	}
}
