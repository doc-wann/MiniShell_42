#include "../includes/minishell.h"

void	cmd_execv(t_data *data)
{
	t_cmd_execv		*cmd_execv;

	cmd_execv = data->cmd_lst;
//	if (!builtin_check(data, cmd_execv->cmd))
	if (!builtin_check(&data->read_line))
		ft_printf("no cmd\n");					// mensagem de erro
	builtin_execv(data, &data->read_line);
}
/*
bool	cmd_create_list(t_data *data)
{
	// create data->cmd_lst
	// Separate cmd & pipe
	// Return True or False
}
*/