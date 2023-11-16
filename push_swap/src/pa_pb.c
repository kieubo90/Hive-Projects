/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:50:42 by vvu               #+#    #+#             */
/*   Updated: 2023/05/19 11:28:44 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_stack **head, t_stack **dest)
{
	t_stack	*temp;

	if (*head == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = *dest;
	*dest = *head;
	*head = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	pa_pb(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	pa_pb(a, b);
	write(1, "pb\n", 3);
}
