/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:18:57 by vvu               #+#    #+#             */
/*   Updated: 2023/05/23 09:15:25 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	check_error_num(ac, av, 1, 0);
	check_error_sign(av, 1, 0);
	b = NULL;
	a = NULL;
	check_inputs(&a, ac, av, 1);
	check_dup(&a);
	check_index(a, stack_size(&a) + 1);
	check_size_and_sort(&a, &b);
	ft_free(&a);
	ft_free(&b);
	return (0);
}
