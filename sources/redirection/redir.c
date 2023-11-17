#include "../includes/minishell.h"
#include <fcntl.h>

int ft_cleanfile(int fd)
{
	char	buf[1];
	char	buf2[1];

	buf2[0] = '0';

	while(read(fd, buf, 1))
		write(fd, buf2, 1);

	return (0);
}

int	write_file(int fd, char *filename)
{
	int controller;
	char buf[1];
	int fdout;

	controller = 1;
	fdout = open(filename, O_CREAT | O_RDWR | O_TRUNC);
	while (controller != 0)
	{
		ft_bzero(buf, 1);
		controller = read(fd, buf, 1);
		if (controller != 0)
			write(fdout, buf, 1);
	}
	close(fdout);
	close(fd);
	return (0);
}

int	write_file_append(int fd, char *filename)
{
	int controller;
	char buf[1];
	int fdout;

	controller = 1;
	fdout = open(filename, O_CREAT | O_RDWR | O_APPEND);
	while (controller != 0)
	{
		ft_bzero(buf, 1);
		controller = read(fd, buf, 1);
		if (controller != 0 && buf[0] != 0)
			write(fdout, buf, 1);
	}
	close(fdout);
	close(fd);
	return (0);
}


int control_stdout(t_data *data, int flag)
{
	(void) data;
 	static int stdout_backup;
	static int pipe_fd[2];

	if (flag == 0)
	{
		stdout_backup = dup(STDOUT_FILENO);
		pipe(pipe_fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
	}
	//Place command call here
	if (flag == 1)
	{
		close(pipe_fd[1]);
		dup2(stdout_backup, STDOUT_FILENO);
	}
	if (flag == 2)
	{
		return (pipe_fd[0]);
	}
	return (0);
}

int control_stdin(t_data *data, int flag)
{
	(void) data;
 	static int stdout_backup;
	static int pipe_fd[2];

	if (flag == 0)
	{
		stdout_backup = dup(STDIN_FILENO);
		pipe(pipe_fd);
		dup2(pipe_fd[1], STDIN_FILENO);
	}
	//Place command call here
	if (flag == 1)
	{
		close(pipe_fd[1]);
		dup2(stdout_backup, STDIN_FILENO);
	}
	if (flag == 2)
	{
		return (pipe_fd[0]);
	}
	return (0);
}

int datarelay(t_data *data)
{
	ft_printf("\nTHIS IS A DATA RELAY\n");

	if (data->cmd_lst != NULL)
	{
		ft_printf("< STARTING CMDLST >\n");

		for(int i = 0; i < ft_arrlen(data->cmd_lst->cmd); i++)
		{
			ft_printf("process[%i] = %s\n", i, data->cmd_lst->cmd[i]);
		}

		ft_printf("index = %i\n", data->cmd_lst->index);

		ft_printf("pid = %i\n", data->cmd_lst->pid);

		ft_printf("int fd_in = %i\n", data->cmd_lst->fd_in);

		ft_printf("int fd_out = %i\n", data->cmd_lst->fd_out);
	}

	ft_printf("\n\n< STARTING DATA >\n");

	for(int i = 0; i < ft_arrlen(data->env); i++)
	{
		ft_printf("env[%i] = %s\n", i, data->env[i]);
	}

	ft_printf("read_line = %s\n", data->read_line);

	ft_printf("token_lst = %s\n", data->token_lst);

	ft_printf("nb_exec = %i\n", data->nb_exec);

	ft_printf("error = %i\n", data->error);

	ft_printf("exit = %i\n", data->exit);

	return 1;
}