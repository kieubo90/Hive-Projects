/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:13:52 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 10:23:15 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	check;

	i = 1;
	while(i < nb)
	{
		check = i * i;
		if (check == nb)
		{	
			return (i);
			break ;
		}
		else if (check > nb)
		{	
			return (0);
			break ;	
		}
		i++;	
	}
	return (i);
}

int	main(void)
{
	printf("%d",ft_sqrt(100));
	return (0);
}