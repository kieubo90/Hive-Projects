/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:05:07 by vvu               #+#    #+#             */
/*   Updated: 2022/08/29 10:37:06 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *c)
{
	int	i;

	i = 0;
	while (*c++)
		i++;
	return (i);
}

void	ft_putchar(char *c)
{
	int	i;

	i = str_len(c);
	write (1, c, i);
}

void	ft_print_numbers(void)
{
	char	*c;

	c = "1 2 3 4 5 6 7 8 9";
	ft_putchar(c);
	ft_putchar("\n");
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
