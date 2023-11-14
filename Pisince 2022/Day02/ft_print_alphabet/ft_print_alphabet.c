/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:48:29 by vvu               #+#    #+#             */
/*   Updated: 2022/08/29 09:52:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c >= 'a' && c <= 'z')
	{
		ft_putchar(c);
		ft_putchar(' ');
		c++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
