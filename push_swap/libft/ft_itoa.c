/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:13:30 by vvu               #+#    #+#             */
/*   Updated: 2022/12/06 14:23:49 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_count(long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	else if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	long	nbr;
	char	*str;
	int		len;

	nbr = nb;
	len = len_count(nb);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	if (nbr == 0)
		str[0] = 0 + 48;
	else if (nbr < 0)
	{
		str[0] = 45;
		nbr *= -1;
	}
	while (len && nbr)
	{
		str[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}
