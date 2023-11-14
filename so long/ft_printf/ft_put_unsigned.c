/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:56:32 by vvu               #+#    #+#             */
/*   Updated: 2022/12/28 11:52:24 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int nbr)
{
	char	*num;
	int		len;

	len = ft_num_len(nbr);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (nbr)
	{
		num[len - 1] = nbr % 10 + 48;
		len--;
		nbr /= 10;
	}
	return (num);
}

int	ft_put_unsigned(unsigned int nbr)
{
	int		len;
	char	*num;

	len = 0;
	if (!nbr)
		len += write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(nbr);
		len = ft_put_str(num);
		free(num);
	}
	return (len);
}
