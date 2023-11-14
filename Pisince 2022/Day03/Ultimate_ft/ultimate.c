/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:56:00 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 13:01:56 by vvu              ###   ########.fr       */
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

void	ultimate(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int	a;
	int	*b;
	int	**c;
	int	***d;
	int	****e;
	int	*****f;
	int	******g;
	int	*******h;
	int	********j;
	int	*********k;

	b = &a;
	c = &b;
	d = &c;
	e = &d;
	f = &e;
	g = &f;
	h = &g;
	j = &h;
	k = &j;
	ultimate(k);
	put_nbr(a);
	return (0);
}