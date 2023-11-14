/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonachi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:58:34 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 09:54:23 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* void	helper(int index, int a, int b)
{

} */

int	ft_fibonacchi(int index)
{
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else 
		return (ft_fibonacchi(index - 1) + ft_fibonacchi(index - 2));
}

int	main(void)
{
	int	i;
	int	check;

	check = 5;
	i = 0;
	while (i < check)
	{
		printf("%d, ",ft_fibonacchi(i));
		i++;
	}
	return (0);
}