/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:31:36 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 17:32:39 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
		return nb * ft_recursive_factorial(nb - 1);
	else
		return (1);
}

int	main(void)
{
	printf("%d\n",ft_recursive_factorial(6));
	return (0);
}