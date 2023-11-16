/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:43:31 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 10:36:25 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_chg(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	get_mv(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->tp;
		if (tmp_b->tp > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->tp) * -1;
		tmp_b = tmp_b->next;
	}
}

void	mv_smallest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		small;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	small = MAXINT;
	while (tmp)
	{
		if (nb_chg(tmp->cost_a) + nb_chg(tmp->cost_b) < nb_chg(small))
		{
			small = nb_chg(tmp->cost_b) + nb_chg(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_sort(a, b, cost_a, cost_b);
}
