/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:09:58 by vvu               #+#    #+#             */
/*   Updated: 2022/12/28 11:51:31 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_hex_check(unsigned int num, const char check)
{
	if (num >= 16)
	{
		ft_hex_check(num / 16, check);
		ft_hex_check(num % 16, check);
	}
	else
	{	
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (check == 'x')
				ft_putchar(num - 10 + 'a');
			else if (check == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_put_hex(unsigned int nbr, const char check)
{
	if (!nbr)
		return (write(1, "0", 1));
	else
		ft_hex_check(nbr, check);
	return (ft_hex_len(nbr));
}
