#include "../includes/minishell.h"

char *ft_backtrack(char *track);

void	builtin_cd(t_data *data)
{
	ft_printf("samba cd");

	char *homepath;
	char *compare;

	compare = ft_strdup("cd");

	homepath = get_env(data->env, "$HOME");

		if (ft_strncmp(data->cmd_lst->next->cmd, "$", 1) == 0)
			data->cmd_lst->next->cmd = get_env(data->env, data->cmd_lst->next->cmd);
		compare = "..";
		if(!data->cmd_lst->next->cmd)
		{
			if (chdir(ft_strjoin("/",homepath)) != 0)
				printf("error when taking you home\n");
		}
		else if (data->cmd_lst->next->cmd)
		{
			if (ft_strncmp(data->cmd_lst->next->cmd, "..\0", 3) == 0)
			{
				chdir(ft_backtrack(getcwd(NULL, 100)));
			}
			else if (ft_strncmp(data->cmd_lst->next->cmd, "../", 3) == 0)
			{
				chdir(ft_backtrack(getcwd(NULL, 100)));
				data->cmd_lst->next->cmd += 3;
				builtin_cd(data);
			}
			else if(chdir(ft_strjoin(getcwd(NULL, 100), path_parser(data->cmd_lst->next->cmd))) != 0)
				write(1, ft_strjoin(ft_strjoin("cd: no such file or directory: ", data->cmd_lst->next->cmd), "\n"), 31 + ft_strlen(data->cmd_lst->next->cmd) + 1);
		}
	else
		return ;
}

//maynotbeneeded :(
char *ft_backtrack(char *track)
{
	int unsigned long i;

	i = 0;
	while(track[i])
		i++;
	while(i > 0 && track[i] != '/')
		i--;
	if (i > 0 && i < ft_strlen(track))
		return (ft_strncpy(track, i));
	else
		return (track);
	
}

char *get_env(char **envs, char *search)
{
	int i;
	char *env;

	env = NULL;
	i = 0;
	if (ft_strlen(search) < 2)
		return (NULL);
	if (ft_strncmp(search, "$ ", 1) == 0)
		search++;
	else
		return (NULL);
	if (search[0] >= 65 && search[0] <= 90)
	{}
	else
		return (NULL);
	search = ft_strjoin(search, "=");
	while(i < ft_lstlen(envs))
	{
		if(ft_strncmp(envs[i], search, ft_strlen(search)) == 0)
		{
			env = envs[i];
			break ;
		}
		else
		{
			i++;
		}
	}
	if (env)
	{
		return(env + ft_strlen(search) + 1);
	}
	else
	{
		return(NULL);
	}
}

char	*path_parser(char *path)
{
	int i;

	i = 0;
	while(!ft_isalnum(path[0]))
		path++;
	path = ft_strjoin("/",path);
	return(path);
}