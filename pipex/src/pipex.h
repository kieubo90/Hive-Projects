/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:47:04 by vvu               #+#    #+#             */
/*   Updated: 2023/11/18 11:29:51 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include "../libft/libft.h"

char	*get_path(char **ev, char *cmd);
void	exec(char *cmd, char **ev);
void	error_code(char *str);
void	error_cmd(char *str);
void	error_sleep(char *str);
void	free_split(char **str);

#endif
