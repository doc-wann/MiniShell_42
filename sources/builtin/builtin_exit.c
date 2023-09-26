#include "../includes/minishell.h"

void	builtin_exit(char **cmd)
{
	(void)cmd;
	exit(1);
}
