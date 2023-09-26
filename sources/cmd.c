#include "../includes/minishell.h"
/*
int spawn_proc (int in, int out, char *cmd)
{
	pid_t	pid;

	if ((pid = fork ()) == 0)
    {
    	if (in != 0)
        {
        	dup2 (in, 0);
        	close (in);
        }
		if (out != 1)
		{
			dup2 (out, 1);
			close (out);
		}
		return execvp (cmd->argv [0], (char * const *)cmd->argv);
    }
	return pid;
}

int fork_pipes (int n, char **cmd)
{
	int		i;
	pid_t	pid;
	int		in;
	int		fd [2];

	in = 0;
	i = 0;
	while (i < n - 1)
    {
		pipe (fd);
		spawn_proc (in, fd [1], cmd + i);
		close (fd [1]);
		in = fd [0];
		i++;
    }
	if (in != 0)
  		dup2 (in, 0);
	return execvp (cmd [i].argv [0], (char * const *)cmd [i].argv);
}
*/
void	cmd_execv(t_data *data)
{
	(void)data;

	while (data->cmd_lst != NULL)
	{
		if (builtin_check(&data->cmd_lst->cmd))
			builtin_execv(data, &data->cmd_lst->cmd);
//		else
//			fork_pipes(4, &data->cmd_lst[i]);
		data->cmd_lst = data->cmd_lst->next;
	}
}
