/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:15:46 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 11:28:50 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack{
	struct s_stack	*next;
	int				data;
	int				index;
	int				pos;
	int				tp;
	int				cost_a;
	int				cost_b;
}	t_stack;

void			arrange_a(t_stack **a, t_stack **b);
void			arrange_b(t_stack **b, t_stack **a);
void			sort_advance(t_stack **a, t_stack **b);
void			sort_5(t_stack **a, t_stack **b);
void			sort_3(t_stack **a);
void			pb(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			rrb(t_stack **b);
void			rra(t_stack **a);
void			rr(t_stack **a, t_stack **b);
void			rb(t_stack **b);
void			ra(t_stack **a);
void			ss(t_stack **a, t_stack **b);
void			sb(t_stack **b);
void			sa(t_stack **a);
void			ft_freestr(char **a);
void			ft_free(t_stack **a);
void			ft_error(void);
void			check_special(t_stack **a);
void			check_dup(t_stack **a);
void			check_valid(char **av, int i);
void			check_error_sign(char **av, int i, int j);
void			put_to_a(t_stack **head, char **av, int i, int num);
void			put_sub_a(t_stack **head, char **av, int i, int num);
void			check_inputs(t_stack **a, int ac, char **av, int j);
void			check_error_num(int ac, char **av, int i, int j);
void			check_size_and_sort(t_stack **a, t_stack **b);
void			check_index(t_stack *a, int size_a);
int				is_space(int c);
int				check_quote(char **av, int i, int j);
int				sorted(t_stack **a);
int				stack_size(t_stack **a);
long int		new_ft_atoi(const char *str);

//From sort advance
void			push_to_b(t_stack **a, t_stack **b);
void			get_tp(t_stack **a, t_stack **b);
void			get_mv(t_stack **a, t_stack **b);
void			mv_smallest(t_stack **a, t_stack **b);
void			do_sort(t_stack **a, t_stack **b, int cost_a, int cost_b);
void			data_position(t_stack **cur);
void			check_a(t_stack **a);
int				nb_chg(int nb);
int				get_last_index(t_stack **a);

#endif
