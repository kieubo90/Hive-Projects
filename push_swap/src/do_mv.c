/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:00:20 by vvu               #+#    #+#             */
/*   Updated: 2023/05/19 11:24:40 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

void	rot_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

void	mv_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

void	mv_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

void	do_sort(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rot_both(a, b, &cost_a, &cost_b);
	mv_a(a, &cost_a);
	mv_b(b, &cost_b);
	pa(a, b);
}
