/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:24:37 by ssalmi            #+#    #+#             */
/*   Updated: 2022/08/27 11:16:17 by vvu              ###   ########.fr       */
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
			ft_putchar('o');
		else if (a == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
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
			ft_putchar('o');
		else if (a == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
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
			ft_putchar('|');
		else if (a == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		a++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	b;

	b = 1;
	if (x > 0 && y > 0)
	{
		print_first_row(x);
		if (y > 2)
		{
			while (b < y - 1)
			{
				print_mid_row(x);
				b++;
			}
		}
		else if (y > 1)
			print_last_row(x);
	}
}
