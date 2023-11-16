/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:26:57 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 11:02:47 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **a)
{
	char	*n;

	if (!a)
		return ;
	while (*a)
	{
		n = *a;
		a++;
		free(n);
	}
	*a = NULL;
}

void	ft_free(t_stack **a)
{
	t_stack	*temp;

	if (!a)
		return ;
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long int	new_ft_atoi(const char *str)
{
	long long int	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if ((result * sign) > MAXINT || (result * sign) < MININT)
		ft_error();
	return (result * sign);
}
