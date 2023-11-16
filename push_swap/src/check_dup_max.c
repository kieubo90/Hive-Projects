/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:00:59 by vvu               #+#    #+#             */
/*   Updated: 2023/05/18 13:54:27 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stack **a)
{
	t_stack	*temp;
	t_stack	*mv;

	temp = *a;
	mv = (*a)->next;
	while (temp->next != NULL)
	{
		while (mv)
		{
			if (temp->data == mv->data)
			{
				ft_free(a);
				ft_error();
			}
			mv = mv->next;
		}
		temp = temp->next;
		mv = temp->next;
	}
}
