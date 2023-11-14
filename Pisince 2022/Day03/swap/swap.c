/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:02:25 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 14:05:02 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	put_nbr(int nbr)
{
	if (nbr >= 10)
	{
		put_nbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putchar(45);
		nbr = -nbr;
		put_nbr(nbr);
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 3;
	put_nbr(a);
	ft_putchar('\n');
	put_nbr(b);
	ft_putchar('\n');
	ft_swap(&a, &b);
	put_nbr(a);
	ft_putchar('\n');
	put_nbr(b);
	return (0);
}