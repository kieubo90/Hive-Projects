/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:06:16 by vvu               #+#    #+#             */
/*   Updated: 2023/01/02 12:35:50 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_put_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (*str)
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}

int	ft_put_nbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		i += ft_putchar(45);
		i += ft_putchar(48 + 2);
		i += ft_put_nbr(147483648);
	}
	else if (nbr < 0)
	{
		i += ft_putchar(45);
		nbr *= -1;
		i += ft_put_nbr(nbr);
	}
	else if (nbr > 9)
	{
		i += ft_put_nbr(nbr / 10);
		i += ft_putchar(nbr % 10 + 48);
	}
	else
		i += ft_putchar(nbr + 48);
	return (i);
}
