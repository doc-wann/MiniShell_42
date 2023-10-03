#include "../includes/minishell.h"

void	builtin_exit(char **cmd, t_data *data)
{
	(void) cmd;
	(void) data;
	exit(1);
}
