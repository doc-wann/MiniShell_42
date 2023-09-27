#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	t_data	data;

	(void)argc;
	(void)argv;
	minishell_init(&data, argc, envp);
	minishell_loop(&data);
//	minishell_exit(&data);
	return (0);
}
