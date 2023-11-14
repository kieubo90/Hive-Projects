/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:51:55 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 08:56:55 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);	
	else if (power-- > 0)
	{
		return(nb * ft_recursive_power(nb, power));
	}
	return(1);
}

int	main(void)
{
	printf("%d",ft_recursive_power(-2,0));
	return (0);
}