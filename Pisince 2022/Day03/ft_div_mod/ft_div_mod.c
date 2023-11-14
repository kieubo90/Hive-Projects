/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:07:06 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 17:54:15 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_div_mod(int a, int b, int *abc, int *cba)
{
	*abc = a / b;
	*cba = a % b;
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

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 5;
	b = 2;
	div = 0;
	mod = 0;
	ft_div_mod(a, b, &div, &mod);
	put_nbr(a);
	ft_putchar('\n');
	put_nbr(b);
	ft_putchar('\n');
	put_nbr(div);
	ft_putchar('\n');
	put_nbr(mod);
	ft_putchar('\n');
	return (0);
}