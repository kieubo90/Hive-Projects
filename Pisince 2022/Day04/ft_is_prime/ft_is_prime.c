/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:44:16 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 16:40:47 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	two;
	int	three;

	two = nb % 2;
	three = nb % 3;
	if (nb == 0 || nb == 1)
		return (0);
	else if (nb == 2 || nb == 3)
		return (1);	
	else if (two == 0 || three == 0)
		return (0);
	else
		return (1);	
}

int	main(void)
{
	printf("%d\n",ft_is_prime(200));
	printf("%d\n",ft_is_prime(31));
	printf("%d\n",ft_is_prime(5));
	return (0);
}