/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:59 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/03 22:46:11 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_cmd_simple(t_data *data, t_cmd_lst *cmd_lst)
{
	char	*path;

	(void)data;
	if (builtin_check(cmd_lst->process))
		exec_builtin(data, cmd_lst->process);
	else
	{
		path = exec_path(cmd_lst->process[0], data->env);
		if (path != NULL)
			execve(path, cmd_lst->process, data->env);
		else
			error_exec_cmd_not_found(cmd_lst->process[0]);
	}
}

int	exec_cmd_multi_child(t_data *data, t_cmd_lst *cmd_lst, int in, int out)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_msg(data, ERROR_FORK);
	if (pid == 0)
	{
		if (in != 0)
		{
			dup2(in, 0);
			close(in);
		}
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		exec_cmd_simple(data, cmd_lst);
	}
//	waitpid(pid, NULL, 0);
	return (pid);
}

void	exec_cmd_multi(t_data *data)
{
	int	in;
	int	out;
	int	fd [2];
	int	i;

	in = 0;
	out = 0;
	i = 0;
	while (i < data->nb_execv - 1)
	{
		pipe(fd);
		out = fd[1];
		exec_cmd_multi_child(data, data->cmd_lst, in, out);
		close(out);
		in = fd[0];
		i++;
		data->cmd_lst = data->cmd_lst->next;
	}
	if (in != 0)
		dup2(in, 0);
	exec_cmd_simple(data, data->cmd_lst);
}

/*
void	exec_cmd_multi(t_data *data)
{
	t_cmd_lst	*cmd_lst;
	pid_t		child;

	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		child = fork();
		if (child < 0)
			error_msg(data, ERROR_FORK);
		if (child == 0)
		{
			exec_cmd_simple(data, cmd_lst);
		}
		else
			cmd_lst->child = child;
		cmd_lst = cmd_lst->next;
	}
}

void	exec_cmd_alone(t_data *data)
{
	t_cmd_lst	*cmd_lst;

	cmd_lst = data->cmd_lst;
//	if (cmd_lst->process == NULL || cmd_lst->process[0] == NULL)
//		return;
//	if (builtin_check(cmd_lst->process))
//		exec_builtin(data, cmd_lst->process);
//	else
//		exec_cmd_simple(data, cmd_lst);

	exec_fd_child(data, cmd_lst);
	exec_cmd_simple(data, cmd_lst);
}
*/

void	exec_cmd(t_data *data)
{
//	if (data->nb_execv > 1)
		exec_cmd_multi(data);
//	else
//		exec_cmd_alone(data);
}































/*
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# define ERR_ARGB "Different from : ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2"
# define ERR_ARGH "Different from : ./pipex here_doc LIMITER cmd cmd1 file"
# define ERR_PIPE "Problem creating pipe"
# define ERR_FILE "File not found"

void	free_mem(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

char	*cmd_path(char *cmd, char **envp)
{
	char	**path;
	char	*path_curr;
	char	*path_firm;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		path_curr = ft_strjoin(path[i], "/");
		path_firm = ft_strjoin(path_curr, cmd);
		free(path_curr);
		if (access(path_firm, F_OK) == 0)
		{
			free_mem(path);
			return (path_firm);
		}
		free(path_firm);
		i++;
	}
	free_mem(path);
	return (NULL);
}

void	cmd_exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = cmd_path(cmd[0], envp);
	if (path != NULL)
	{
		if (execve(path, cmd, envp) < 0)
		{
			free_mem(cmd);
			ft_error_cmd(argv);
		}
		free_mem(cmd);
	}
	else
	{
		free_mem(cmd);
		ft_error_cmd(argv);
	}
}

void	child_cmd(char *argv, char **envp)
{
	pid_t	child;
	int		fd[2];

	if (pipe(fd) < 0)
		ft_error(ERR_PIPE);
	child = fork();
	if (child < 0)
		ft_error(strerror(errno));
	if (child == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			ft_error(strerror(errno));
		cmd_exec(argv, envp);
	}
	if (dup2(fd[0], STDIN_FILENO) < 0)
		ft_error(strerror(errno));
	close(fd[0]);
	close(fd[1]);
	waitpid(child, NULL, 0);
}

void	multi_cmd(t_data *data)
{
	int		file1;
	int		file2;
	int		cmd;

	file1 = open(argv[1], O_RDONLY, 0777);
	file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file1 < 0)
		ft_error(ERR_FILE);
	if (file2 < 0)
		ft_error(ERR_FILE);
	dup2(file1, STDIN_FILENO);
	cmd = 2;
	while (cmd < (argc - 2))
	{
		child_cmd(argv[cmd], envp);
		cmd++;
	}
	dup2(file2, STDOUT_FILENO);
	cmd_exec(argv[argc - 2], envp);
}
*/