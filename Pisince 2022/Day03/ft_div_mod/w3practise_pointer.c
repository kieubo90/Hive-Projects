/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3practise_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:34:50 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 16:07:34 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	m;
	int	*ab;

	m = 29;
	ab = &m;
	printf("%p\n", ab);
	printf("%p\n", &m);
	printf("%i\n", *ab);
	m = 34;
	printf("%p\n", ab);
	printf("%i\n", *ab);
	*ab = 7;
	printf("%p\n", ab);
	printf("%i\n", *ab);

	return (0);
}