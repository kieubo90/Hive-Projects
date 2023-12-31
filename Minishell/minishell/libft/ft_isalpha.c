/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:50:42 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/22 10:50:44 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int n)
{
	int	answer;

	answer = 0;
	if ((n > 64 && n < 91) || (n > 96 && n < 123))
		answer = 1;
	else
		answer = 0;
	return (answer);
}
