/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:05:42 by vvu               #+#    #+#             */
/*   Updated: 2022/08/26 09:25:51 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *argv)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc (sizeof(char) * ft_strlen(argv));
	if (!(new))
		return (NULL);
	while (argv[i] != '\0')
	{
		new[i] = argv[i];
		i++;
	}
	return (new);
}

int	main(int argc, char **argv)
{
	char	*mine;
	char	*computer;

	mine = NULL;
	computer = NULL;
	if (argc == 2)
	{
		mine = ft_strdup(argv[1]);
		computer = strdup(argv[1]);
	}
	printf (":%s:\n:%s:\n", mine, computer);
	return (0);
}
