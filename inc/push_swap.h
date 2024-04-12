/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:36:06 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 16:16:32 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	top;
	int	*istack; //TODO:shorten name??
}				t_stack;

typedef struct s_operation //TODO:shorten name?
{
	int	idx;
	int	c_ra;
	int	c_rra;
	int	c_rb;
	int	c_rrb;
	int	c_rr;
	int	c_rrr;
	int	c_sum;
}				t_operation;

int			is_args_int(int len, char **args);
int			is_args_unique(int len, char **args);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

t_stack		*init_sa(int len, char **av);
t_stack		*init_sb(int len);

void		turk_sort(t_stack *a, t_stack *b);

int			get_min_idx(t_stack *s);
int			get_target_idxa(int value, t_stack *a);
int			get_target_idxb(int value, t_stack *b);

int			is_sorted(t_stack *a);
t_operation	get_op_to_top(t_stack *a, t_stack *b, int idxa, int idxb);
t_operation	get_cheap_op_pb(t_stack *a, t_stack *b);
t_operation	get_cheap_op_pa(t_stack *a, t_stack *b);
void		execute_op(t_stack *a, t_stack *b, t_operation op);

void		pb3(t_stack *a, t_stack *b);
void		sort_under_three_asc(t_stack *a);
void		sort_three_desc(t_stack *b);

#endif
