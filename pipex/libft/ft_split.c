/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:17:57 by vvu               #+#    #+#             */
/*   Updated: 2023/06/15 16:41:19 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
		{
			count++;
			s++;
			while (*s != 34 && *s != 39 && *s)
				s++;
		}
		else if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			count++;
			s++;
		}
		else
			s++;
	}
	return (count);
}

static void	mv_in_quote(int *i, int *j, char const *s, char check)
{
	*j = *i;
	if (s[*i] == 34 || s[*i] == 39)
	{
		(*i)++;
		*j = *i;
		while (s[*i] != 34 && s[*i] != 39 && s[*i])
			(*i)++;
	}
	else
		while (s[*i] != check && s[*i])
			(*i)++;
}

static char	*slpit_sentence(char const *s, char check, int *i)
{
	char	*new;
	int		j;
	int		k;

	k = 0;
	mv_in_quote(i, &j, s, check);
	new = malloc(sizeof(char) * (*i - j + 1));
	if (!new)
		return (NULL);
	while (j < *i)
		new[k++] = s[j++];
	new[k] = '\0';
	if (s[*i] == 34 || s[*i] == 39)
		(*i)++;
	while (s[*i] == check && check != '\0')
		(*i)++;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	int		array_count;
	int		j;
	int		i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	j = 0;
	array_count = count(s, c);
	d = malloc((sizeof(char *) * (array_count + 1)));
	if (!d)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
			d[j++] = slpit_sentence(s, c, &i);
		else if (s[i] == c)
			i++;
	}
	d[j] = NULL;
	return (d);
}
