/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:39:15 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 11:08:26 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
		sign = -1;	
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{	
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("%i\n", ft_atoi("123"));
	printf("atoi: %i\n", atoi("123"));
	printf("%i\n", ft_atoi("-123"));
	printf("atoi: %i\n", atoi("-123"));

	printf("%i\n", ft_atoi("++123"));
	printf("atoi: %i\n", atoi("++123"));
	printf("%i\n", ft_atoi("--123"));
	printf("atoi: %i\n", atoi("--123"));

	printf("%i\n", ft_atoi("	123dfdf fsd 123"));
	printf("%i\n", atoi("	123dfdf fsd 123"));
	return (0);
}