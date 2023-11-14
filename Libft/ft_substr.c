/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:09:13 by vvu               #+#    #+#             */
/*   Updated: 2022/12/20 15:22:59 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			j;
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	s = s + start;
	while (*s && j < len && start < i)
	{
		str[j]= *s;
		s++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
