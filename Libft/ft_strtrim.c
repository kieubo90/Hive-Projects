/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:45:50 by vvu               #+#    #+#             */
/*   Updated: 2022/12/06 14:26:27 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		end;
	char	*str_trim;

	if (!s1 || !s2)
		return (NULL);
	while (*s1 && ft_strchr(s2, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(s2, s1[end]))
		end--;
	str_trim = ft_substr(s1, 0, end + 1);
	return (str_trim);
}
