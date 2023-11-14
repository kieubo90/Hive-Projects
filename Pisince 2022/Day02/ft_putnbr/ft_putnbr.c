/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:44:39 by vvu               #+#    #+#             */
/*   Updated: 2022/08/29 15:49:41 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar(45);
		ft_putchar(50);
		ft_putnbr(147483648);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putchar(45);
		nb = -nb;
		ft_putnbr(nb);
	}
}

int	main(void)
{
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(2147447);
	ft_putchar('\n');
	ft_putnbr(-2147447);
	ft_putchar('\n');
	return (0);
}
