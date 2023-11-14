/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:44:48 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 16:09:38 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char	*ft_strrev(char *str)
{
	char	temp;
	int		begin;
	int		end;
	int		i;
	

	begin = 0;
	end = 0;
	i = 0;
	while (str[end])
		end++;
	end--;	
	while (end >= i)
	{
		temp = str[end];
		str[begin] = str[end];
		str[end] = temp;
		end--;
		begin++;
 	}
	return (str);	
} 

int	main(void)
{

	char	*c;
	int		i;

	i = 0;	
	c =(char *)malloc(sizeof(char) * 6); 
	while (i < 6)
	{	
		c[i] = 'a';
		i++;
	}
	return (0);
}