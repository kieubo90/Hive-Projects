/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:48:05 by vvu               #+#    #+#             */
/*   Updated: 2023/05/22 11:28:37 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(int c)
{
	return (c == 32);
}

int	check_quote(char **av, int i, int j)
{
	while (av[i][j] == 32)
	{
		if (av[i][j + 1] == '\0')
			return (0);
		j++;
	}
	j = 0;
	while (av[i][j] != '\0')
	{
		j++;
		if (is_space(av[i][j]))
			return (1);
	}
	return (0);
}

void	check_special(t_stack **a)
{
	ft_free(a);
	ft_error();
}

void	check_inputs(t_stack **a, int ac, char **av, int j)
{
	int	i;

	i = 1;
	if (ac < 2)
		exit(0);
	else if (ac == 2)
		put_to_a(a, av, 1, 0);
	else
	{
		while (av[i])
		{
			if (check_quote(av, i, 0) && j)
			{
				put_to_a(a, av, i, 0);
				j--;
			}
			else if (check_quote(av, i, 0) && !j)
				check_special(a);
			else
				put_sub_a(a, av, i, 0);
			i++;
		}
	}
}
