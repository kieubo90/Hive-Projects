/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:38:22 by vvu               #+#    #+#             */
/*   Updated: 2022/12/07 17:35:37 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_check(va_list args, const char str);
int		ft_hex_len(unsigned int nbr);
void	ft_hex_check(unsigned int num, const char check);
int		ft_put_hex(unsigned int nbr, const char check);
int		ft_put_percent(void);
int		ft_put_str(char	*str);
int		ft_put_nbr(int nbr);
int		ft_ptr_len(unsigned long long nbr);
void	ft_ptr_check(unsigned long long nbr);
int		ft_put_ptr(unsigned long long nbr);
int		ft_num_len(unsigned int nbr);
char	*ft_unsigned_itoa(unsigned int nbr);
int		ft_put_unsigned(unsigned int nbr);

#endif
