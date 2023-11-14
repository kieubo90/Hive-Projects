/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:53:23 by vvu               #+#    #+#             */
/*   Updated: 2022/08/29 10:04:09 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a' && c <= 'z')
	{
		ft_putchar(c);
		ft_putchar(' ');
		c--;
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
