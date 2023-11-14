/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:49:24 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 12:55:19 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

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
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putchar(45);
		nbr = -nbr;
		put_nbr(nbr);
	}
}

int	main(void)
{
	int	a;	
	int	*nbr;

	nbr = &a;
	ft_ft(nbr);
	put_nbr(a);
	ft_putchar('\n');
}
