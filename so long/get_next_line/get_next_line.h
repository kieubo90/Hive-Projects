/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:14:07 by vvu               #+#    #+#             */
/*   Updated: 2023/05/31 12:31:33 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_strjoin1(char *str, char *buff);
char	*ft_new_str(char *str);
int		ft_strlen1(char *str);
char	*ft_read(char *str, int fd);
char	*ft_strchr1(char *s, int c);
#endif
