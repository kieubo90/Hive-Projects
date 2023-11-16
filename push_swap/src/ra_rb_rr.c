/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:35:23 by vvu               #+#    #+#             */
/*   Updated: 2023/03/17 15:56:10 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack **a)
{
	t_stack	*temp;
	t_stack	*tail;

	tail = *a;
	while (tail && tail->next != NULL)
		tail = tail->next;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	tail->next = temp;
}

void	ra(t_stack **a)
{
	ra_rb(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ra_rb(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra_rb(a);
	ra_rb(b);
	write(1, "rr\n", 3);
}
