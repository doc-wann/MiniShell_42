#include "../includes/minishell.h"

void	builtin_env(t_data *data)
{
	char	**env;

	env = data->env;
	if (!env)
		return;
	while (*env)
	{
		ft_printf("%s\n", *env);
		env++;
	}
}
