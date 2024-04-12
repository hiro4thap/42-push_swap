/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:26:05 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 18:57:59 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "./get_next_line.h"

typedef struct s_stack
{
	int	top;
	int	*istk;
}				t_stack;

typedef struct s_operation
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
int			is_valid_inst(char *isnt);

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

int			is_sorted(t_stack *a);

#endif
