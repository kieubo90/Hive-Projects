/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:26:09 by vvu               #+#    #+#             */
/*   Updated: 2022/12/01 13:49:26 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pt;

	pt = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*pt++ == (unsigned char)c)
			return (--pt);
	}
	return (NULL);
}
