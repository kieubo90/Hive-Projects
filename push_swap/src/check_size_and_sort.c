/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_and_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:19:24 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 09:26:44 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **a)
{
	int		size;
	t_stack	*temp;

	temp = *a;
	size = 0;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

int	sorted(t_stack **a)
{
	t_stack	*temp;
	int		size;

	size = stack_size(a);
	temp = *a;
	while (--size)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	check_size_and_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = 0;
	size = stack_size(a);
	if (size == 1 || sorted(a) == 1)
	{
		ft_free(a);
		exit(0);
	}
	else if (size < 4 && size > 1)
		sort_3(a);
	else if (size > 3)
		sort_advance(a, b);
}
