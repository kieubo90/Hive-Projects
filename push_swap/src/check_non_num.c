/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_non_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:20:11 by vvu               #+#    #+#             */
/*   Updated: 2023/05/22 11:28:39 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_not_digit(int c)
{
	if ((c > 32 && c < 43) || (c == 44) || (c == 46) || (c == 47)
		|| (c > 57 && c < 127))
		return (1);
	return (0);
}

void	only_space(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 32)
				j++;
			else if (av[i][j] != 32)
				return ;
			else
				j++;
		}
		i++;
	}
	if (av[i - 1][j] == '\0')
		exit (0);
}

void	check_error_num(int ac, char **av, int i, int j)
{
	if (ac <= 2)
	{
		if (!av[i] || !av[i][j])
			exit(0);
		only_space(av);
	}
	else if (ac > 2)
		only_space(av);
	while (av[i])
	{
		while ((av[i][j]) != '\0')
		{
			if (is_not_digit(av[i][j]))
				ft_error();
			j++;
		}
		i++;
		j = 0;
	}
}
