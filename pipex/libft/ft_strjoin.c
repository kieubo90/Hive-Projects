/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:21:01 by vvu               #+#    #+#             */
/*   Updated: 2022/12/02 16:15:14 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (i + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	join[i] = '\0';
	while (*s2)
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
