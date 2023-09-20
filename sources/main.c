#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	minishell_init(&data, argc, envp);
	minishell_loop(&data);
//	minishell_exit(&data);
	return (0);
}
