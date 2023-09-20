#include "../includes/minishell.h"

void	check_data(int argc)
{
	if (!isatty(0))
		error_msg("error");
	if (argc != 1)
		error_msg("error");
}

void	init_data(t_data *data)
{
	data->env = NULL;
	data->exit = 0;
}

bool	init_env(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
		i++;
	data->env = ft_calloc(i + 1, sizeof * data->env);
	if (data->env == NULL)
		return (false);
	i = 0;
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		if (data->env[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

void	minishell_init(t_data *data, int argc, char **envp)
{
	check_data(argc);
	init_data(data);
	if (!init_env(data, envp))
		error_msg("error");
}

