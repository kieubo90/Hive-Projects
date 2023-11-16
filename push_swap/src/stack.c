/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:25:41 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 11:03:38 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_memory(int new_data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof * new_node);
	if (new_node)
	{
		new_node->data = new_data;
		new_node->index = 0;
		new_node->pos = -1;
		new_node->tp = -1;
		new_node->cost_a = -1;
		new_node->cost_b = -1;
		new_node->next = NULL;
	}
	else
		ft_error();
	return (new_node);
}

void	put_to_a(t_stack **head, char **av, int i, int num)
{
	char	**arg;
	t_stack	*b;
	int		j;

	j = 0;
	arg = ft_split(av[i], 32);
	b = *head;
	while (arg[j])
	{
		num = new_ft_atoi(arg[j++]);
		if ((*head) == NULL)
		{
			(*head) = create_memory(num);
			b = (*head);
		}
		else
		{
			while (b->next)
				b = b->next;
			b->next = create_memory(num);
			b = b->next;
		}
	}
	ft_freestr(arg);
	free(arg);
}

void	put_sub_a(t_stack **head, char **av, int i, int num)
{
	t_stack	*b;
	int		j;

	j = 0;
	while (av[i][j] == 32)
	{
		if (av[i][j + 1] == '\0')
			return ;
		j++;
	}
	b = *head;
	num = new_ft_atoi(av[i]);
	if ((*head) == NULL)
	{
		*head = create_memory(num);
		b = (*head);
	}
	else
	{
		while (b->next)
			b = b->next;
		b->next = create_memory(num);
		b = b->next;
	}
}
