/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:24:37 by ssalmi            #+#    #+#             */
/*   Updated: 2022/08/28 12:37:06 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_first_row(int x)
{
	int	a;

	a = 0;
	while (a < x)
	{
		if (a == 0)
			ft_putchar('A');
		else if (a == x - 1)
			ft_putchar('A');
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
			ft_putchar('C');
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

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc == 3)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[2]);
	}
	else
		ft_putchar('\n');
	rush (a, b);
	return(0);
}
