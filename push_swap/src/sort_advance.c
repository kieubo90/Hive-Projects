/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_advance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:02:46 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 10:37:33 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	size_a;
	int	i;
	int	count;

	size_a = stack_size(a);
	count = 0;
	i = 0;
	while (size_a > 6 && i < size_a && count < size_a / 2)
	{
		if ((*a)->index <= size_a / 2)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
		i++;
	}
	while (size_a - count > 3)
	{
		pb(a, b);
		count++;
	}
}

int	get_last_index(t_stack **a)
{
	t_stack	*tmp;
	int		last_idx;
	int		last_pos;

	tmp = *a;
	last_idx = MAXINT;
	data_position(a);
	last_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < last_idx)
		{
			last_idx = tmp->index;
			last_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (last_pos);
}

void	check_a(t_stack **a)
{
	int	last_pos;
	int	size;

	size = stack_size(a);
	last_pos = get_last_index(a);
	if (last_pos > size / 2)
	{
		while (last_pos < size)
		{
			rra(a);
			last_pos++;
		}
	}
	else
	{
		while (last_pos > 0)
		{
			ra(a);
			last_pos--;
		}
	}
}

void	sort_advance(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	sort_3(a);
	while (*b)
	{
		get_tp(a, b);
		get_mv(a, b);
		mv_smallest(a, b);
	}
	if (!sorted(a))
		check_a(a);
}
