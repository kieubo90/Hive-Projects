/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:12 by vvu               #+#    #+#             */
/*   Updated: 2022/12/28 11:52:11 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long nbr)
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

void	ft_ptr_check(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_ptr_check(nbr / 16);
		ft_ptr_check(nbr % 16);
	}
	else
	{	
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

int	ft_put_ptr(unsigned long long nbr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (!nbr)
		len += write(1, "0", 1);
	else
	{
		ft_ptr_check(nbr);
		len += ft_ptr_len(nbr);
	}
	return (len);
}
