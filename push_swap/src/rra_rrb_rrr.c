/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:43:06 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 10:36:39 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_stack **a)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*b_tail;

	tail = *a;
	b_tail = *a;
	while (tail && tail->next != NULL)
		tail = tail->next;
	while (b_tail && b_tail->next && b_tail->next->next != NULL)
		b_tail = b_tail->next;
	temp = *a;
	*a = tail;
	(*a)->next = temp;
	b_tail->next = NULL;
}

void	rra(t_stack **a)
{
	rra_rrb(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rra_rrb(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a);
	rra_rrb(b);
	write(1, "rrr\n", 4);
}
