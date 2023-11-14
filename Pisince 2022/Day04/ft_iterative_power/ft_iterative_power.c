/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:14:04 by vvu               #+#    #+#             */
/*   Updated: 2022/08/31 18:26:38 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb,int power)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (power < 0)
	 return (0);
	while(i++ < power)
		result *= nb;
	return (result);
}

int	main(void)
{
	int	i;

	i = 1000;
	printf("%d",ft_iterative_power(i, 4));
	return (0);
}