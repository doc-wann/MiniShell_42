#include "../includes/minishell.h"

void	put_endl(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

void	builtin_pwd(char **cmd)
{
	char	*buf;
	char	*cwd;

	(void)cmd;
	cwd = NULL;
	buf = NULL;
	cwd = getcwd(buf, 100);
	if (cwd)
	{
		put_endl(cwd, 1);
		free(buf);
		free(cwd);
		return ;
	}
	if (!cwd)
		ft_printf("no pwd\n");
	return ;
}

