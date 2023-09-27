#include "../includes/minishell.h"

static int	count_args(char **args)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

void	builtin_echo(char **args)
{
	int		i;
	int		n_flag;

	i = 0;
	n_flag = 0;

	if (count_args(args) > 1)
	{
		// while (args[i] && ft_strncmp(args[i], "-n", 2) == 0)
		// {
		// 	n_flag = 1;
		// 	i++;
		// }
		while (args[i])
		{
			write(1, args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_flag == 1)
	{
		write(1, "\n", 1);
	}

	return ;
}
