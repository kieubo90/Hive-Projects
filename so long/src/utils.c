/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:28:24 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 17:03:42 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_itoa(int n, int nbr)
{
	char	*str;
	int		check;

	check = n;
	if (n == 0)
	{
		str = ft_calloc(2, 1);
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		n /= 10;
		nbr++;
	}
	str = malloc(nbr + 1);
	str[nbr] = '\0';
	while (check != 0 && nbr >= 0)
	{
		str[nbr - 1] = check % 10 + '0';
		check /= 10;
		nbr--;
	}
	return (str);
}
