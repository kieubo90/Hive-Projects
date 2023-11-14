/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:59:48 by vvu               #+#    #+#             */
/*   Updated: 2022/08/31 17:22:48 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_space(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	helper(int tab[], int k, int n, int max)
{
	int input;

	while (k > 0)
	{
		k = 0;
		max = 9;
		while (k < n)
			ft_putchar(tab[k++] + '0');
		while (k--)
		{
			input = tab[k];
			if (input < max--)
			{
				while (k < n)
					tab[k++] = ++input;
				print_space();
				break ;
			}
		}	
	}
	ft_putchar('\n');
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[n];
	
	if (n <= 0 || n >= 10)
		write (1, "\n", 1);
	i = 0;
	while(i < n)
	{	
		tab[i] = i;
		i++;
	}
	helper(tab, 1, n, 9);
}

int	main(void)
{
	ft_print_combn(7);
	return (0);
}