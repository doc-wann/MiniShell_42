#include "../includes/minishell.h"

int datarelay(t_data *data)
{
	ft_printf("\nTHIS IS A DATA RELAY\n");

	if (data->cmd_lst != NULL)
	{
		ft_printf("< STARTING CMDLST >\n");

		ft_printf("cmd = %s\n", data->cmd_lst->cmd);

		for(int i = 0; i < ft_lstlen(data->cmd_lst->process); i++)
		{
			ft_printf("process[%i] = %s\n", i, data->cmd_lst->process[i]);
		}

		ft_printf("parser = %s\n", data->cmd_lst->parser);

		ft_printf("index = %i\n", data->cmd_lst->index);

		ft_printf("pid = %i\n", data->cmd_lst->child);

		ft_printf("int fd_in = %i\n", data->cmd_lst->fd_in);

		ft_printf("int fd_out = %i\n", data->cmd_lst->fd_out);
	}

	ft_printf("\n\n< STARTING DATA >\n");

	for(int i = 0; i < ft_lstlen(data->env); i++)
	{
		ft_printf("env[%i] = %s\n", i, data->env[i]);
	}

	ft_printf("read_line = %s\n", data->read_line);

	ft_printf("nb_execv = %i\n", data->nb_execv);

	ft_printf("error = %i\n", data->error);

	ft_printf("exit = %i\n", data->exit);

	return 1;
}