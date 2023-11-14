/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fromstackoverflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:37:15 by vvu               #+#    #+#             */
/*   Updated: 2022/08/30 09:58:57 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char a)
{
    write(1, &a, 1);
}

void    ft_print_combn(int n)
{
    int combn[n];
    int p;

    if (n <= 0 || n > 10)
       ft_putchar('\n');
    else
    {
        p = 0;
        while (p < n)
        {
            combn[p] = p;
			p++;
        }
        while (p > 0)
        {
            int maxdigit;

			maxdigit = 9;
            p = 0;
			while (p < n)
                ft_putchar(combn[p++] + '0');
            while (p--)
            {
                int digit = combn[p];
                if (digit < maxdigit--)
                {
                    while (p < n)
						combn[p++] = ++digit;
                    ft_putchar(',');
                    ft_putchar(' ');
                   	break ;
                }
            }
        }
        ft_putchar('\n');
    }
}

int main()
{
    ft_print_combn(9);   
}