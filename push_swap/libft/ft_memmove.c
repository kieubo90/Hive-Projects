/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:36:35 by vvu               #+#    #+#             */
/*   Updated: 2022/12/06 14:19:57 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *st1, const void *st2, size_t n)
{
	char		*dst;
	char const	*src;

	dst = (char *)st1;
	src = (char const *)st2;
	if (dst <= src)
		ft_memcpy(dst, src, n);
	else
		while (n--)
			*(dst + n) = *(src + n);
	return (dst);
}
