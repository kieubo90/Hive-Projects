/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:12:25 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 16:29:52 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	put_nbr(int nb)
{
	if (nb > 10)
	{
		put_nbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putchar(45);
		nb = -nb;
		put_nbr(nb);
	}	
}
int	ft_iterative_factorial(int nb)
{
	int i;
	int	add;
	
	i = nb;
	add = 1;
	while (i-- > 1)
		add = add * nb--;
	return (add);
}

int	main(void)
{
	int	i;
	int	result;

	i = 5;
	result = ft_iterative_factorial(i);
	put_nbr(result);
	ft_putchar('\n');
	return (0);
}