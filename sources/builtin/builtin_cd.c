#include "../includes/minishell.h"

char *ft_backtrack(char *track);

void	builtin_cd(char **cmd, t_data *data)
{
	char *homepath;
	char *buffer;

	cmd =  ft_varfetch(cmd, data);

	//THIS IS MERELY A "JUST TO MAKE IT WORK" SOLUTION
	cmd[0] += 2;
	cmd[0] = ft_strtrim(cmd[0], " ");

	homepath = get_env(data->env, "$HOME");

	buffer = getcwd(NULL, 0);

	if (!chdir(cmd[0]))
	{
		if (ft_strncmp(cmd[0], "..\0", 3) == 0)
			chdir(ft_backtrack(buffer));
		if (ft_strncmp(cmd[0], "../", 3) == 0)
		{
			chdir(ft_backtrack(buffer));
			cmd[0] += 3;
			builtin_cd(cmd, data);
		}
	}
	free(buffer);
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

	if (ft_strncmp(search, "%", 1) == 0 && ft_strlen(search) > 1)
		search += 1;

	i = 0;
	while (i++ < ft_lstlen(envs) - 1)
	{
		if (ft_strncmp(search, envs[i], ft_strlen(search)) == 0)
		{
			return (envs[i] + ft_strlen(search) + 1);
		}
	}
	return(ft_strjoin("%", search));
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