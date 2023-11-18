/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:34:46 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 11:31:49 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **ev, char *cmd)
{
	int		i;
	char	*path;
	char	**paths;
	char	*add_slash;

	i = 0;
	while (!ft_strnstr(ev[i], "PATH", 4))
		i++;
	paths = ft_split(ev[i] + 5, ':');
	i = 0;
	while (paths[++i])
	{
		add_slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (!access(path, F_OK))
		{
			free_split(paths);
			return (path);
		}
		free(path);
	}
	free_split(paths);
	return (NULL);
}

void	exec(char *cmd, char **ev)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (execve(cmd_arr[0], cmd_arr, ev) == -1)
		{
			free_split(cmd_arr);
			error_cmd(cmd);
		}
	}
	else if (cmd_arr[0] && get_path(ev, cmd_arr[0]))
	{
		if (execve(get_path(ev, cmd_arr[0]), cmd_arr, ev) == -1)
		{
			free_split(cmd_arr);
			error_cmd(cmd);
		}
		free_split(cmd_arr);
	}
	else
	{
		free_split(cmd_arr);
		error_cmd(cmd);
	}
}
