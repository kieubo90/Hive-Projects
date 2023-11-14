/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:22:00 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 14:21:54 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_integer_table(int *tab, int size)
{
	int	new_array[size];
	int	i;
	int	j;
	int	input;

	i = 0;
	while (i < size)
	{
		new_array[i] = tab[i];
		i++;
	}
	i = 0;
	j = 1;
	while (i < size)
	{	
		while (j < size)
		{
			if (new_array[i] > new_array[j])
			{
				input = new_array[i];
				new_array[i] = new_array[j];
				new_array[j] = input;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	i = 0;
	while (i < size)
	{	
		printf("%d, ",new_array[i]);
		i++;
	}
}

int	main(void)
{
	int	array[] = {10,4,30,8,25,9,10,-20,15,16};
	ft_sort_integer_table(array, 10);
	return (0);
}