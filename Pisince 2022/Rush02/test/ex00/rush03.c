/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:24:37 by ssalmi            #+#    #+#             */
/*   Updated: 2022/08/14 18:17:56 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first_row(int x)
{
	int	a;

	a = 0;
	while (a < x)
	{
		if (a == 0)
			ft_putchar('A');
		else if (a == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		a++;
	}
	ft_putchar('\n');
}

void	print_last_row(int x)
{
	int	a;

	a = 0;
	while (a < x)
	{
		if (a == 0)
			ft_putchar('A');
		else if (a == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		a++;
	}
	ft_putchar('\n');
}

void	print_mid_row(int x)
{
	int	a;

	a = 0;
	while (a < x)
	{
		if (a == 0)
			ft_putchar('B');
		else if (a == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		a++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	b;

	b = 0;
	if (x > 0 && y > 0)
	{
		print_first_row(x);
		b++;
		if (y > 2)
		{
			while (b < y - 1)
			{
				print_mid_row(x);
				b++;
			}
		}
		if (y > 1)
			print_last_row(x);
	}
}
