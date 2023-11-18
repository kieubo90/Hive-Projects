/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:34:11 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 11:31:56 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_code(char *str)
{
	if (errno == 0)
	{
		write(2, "pipex: ", 7);
		write (2, str, ft_strlen(str));
	}
	else
	{
		write(2, "pipex: ", 7);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, ": ", 2);
		write (2, str, ft_strlen(str));
		write (2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	error_cmd(char *str)
{
	write (2, "pipex: command not found: ", 26);
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		free(*str);
		str++;
		i++;
	}
	free(str - i);
}
