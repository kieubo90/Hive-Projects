/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_tp_mv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:22:22 by vvu               #+#    #+#             */
/*   Updated: 2023/06/07 14:05:13 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_position(t_stack **cur)
{
	t_stack	*tmp;
	int		i;

	tmp = *cur;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	check_index(t_stack *a, int size_a)
{
	t_stack	*cur;
	t_stack	*high;
	int		data;

	while (--size_a > 0)
	{
		cur = a;
		data = MININT;
		high = NULL;
		while (cur)
		{
			if (cur->data == MININT && cur->index == 0)
				cur->index = 1;
			if (cur->data > data && cur->index == 0)
			{
				data = cur->data;
				high = cur;
				cur = a;
			}
			else
				cur = cur->next;
		}
		if (high != NULL)
			high->index = size_a;
	}
}

int	tp_extend(t_stack **a, int b_idx, int tp_idx, int tp)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > b_idx && tmp->index < tp_idx)
		{
			tp_idx = tmp->index;
			tp = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (tp_idx != MAXINT)
		return (tp);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < tp_idx)
		{
			tp_idx = tmp->index;
			tp = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tp);
}

void	get_tp(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		tp;

	tmp_b = *b;
	data_position(a);
	data_position(b);
	tp = 0;
	while (tmp_b)
	{
		tp = tp_extend(a, tmp_b->index, MAXINT, tp);
		tmp_b->tp = tp;
		tmp_b = tmp_b->next;
	}
}
