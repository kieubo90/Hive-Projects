/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:07:23 by vvu               #+#    #+#             */
/*   Updated: 2023/05/18 09:12:17 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	check_error_sign(char **av, int i, int j)
{
	while (av[i])
	{
		while (av[i][j] != '\0')
		{
			if (sign(av[i][j]))
			{
				j++;
				if (!(digit(av[i][j])))
					ft_error();
			}
			else
				j++;
		}
		i++;
		j = 0;
	}
}
