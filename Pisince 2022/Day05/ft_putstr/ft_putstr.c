/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:14:15 by vvu               #+#    #+#             */
/*   Updated: 2022/09/01 12:18:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *c)
{
	int	i;

	i = 0;
	while (*c++)
		i++;
	return (i);
}


void	ft_putstr(char *str)
{
	int	len;

	len = str_len(str);
	write (1, str, len);
}

int	main(void)
{
	ft_putstr("abc");
	return (0);
}