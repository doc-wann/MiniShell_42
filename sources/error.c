#include "../includes/minishell.h"

void	error_msg(char	*msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
}
