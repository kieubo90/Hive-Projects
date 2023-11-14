/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:12:09 by jervasti          #+#    #+#             */
/*   Updated: 2022/12/06 14:19:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total;

	if (!nmemb || !size)
		return (ft_calloc(1, 1));
	total = nmemb * size;
	if (total / nmemb != size)
		return (NULL);
	p = malloc(size * nmemb);
	if (!p)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	return (p);
}
