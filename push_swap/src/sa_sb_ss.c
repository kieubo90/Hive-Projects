/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:20:57 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 10:17:31 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **a)
{
	int	temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	temp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp;
}

void	sa(t_stack **a)
{
	sa_sb(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	sa_sb(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a);
	sa_sb(b);
	write(1, "ss\n", 3);
}
