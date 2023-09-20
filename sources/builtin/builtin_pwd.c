#include "../includes/minishell.h"

void	builtin_pwd(char **cmd)
{
	char	*path;

	(void)cmd;
	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		ft_printf("no pwd\n");					// mensagem de erro
	ft_printf("%s\n", path);
}
