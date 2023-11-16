/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:45:39 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 10:37:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_index(t_stack *a)
{
	int	index;

	index = a->index;
	while (a)
	{
		if (a->index > index)
			index = a->index;
		a = a->next;
	}
	return (index);
}

void	sort_3(t_stack **a)
{
	int	highest;

	if (sorted(a))
		return ;
	highest = highest_index(*a);
	if ((*a)->index == highest)
		ra(a);
	else if ((*a)->next->index == highest)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
