/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:12:23 by vvu               #+#    #+#             */
/*   Updated: 2022/08/29 11:17:42 by vvu              ###   ########.fr       */
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

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar("N");
	else if (n >= 0 || n == (int) NULL)
		ft_putchar("P");
}

int	main(void)
{
	ft_is_negative(-1);
	ft_putchar("\n");
	ft_is_negative(0);
	ft_putchar("\n");
	ft_is_negative((int) NULL);
	ft_putchar("\n");
	ft_is_negative(2);
	ft_putchar("\n");
	return (0);
}
