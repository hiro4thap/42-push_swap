/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:26:05 by hiono             #+#    #+#             */
/*   Updated: 2024/04/13 15:47:35 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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

size_t		gnl_ft_strlen(const char *str);
char		*gnl_ft_substr(char const *s, unsigned int start, size_t len);
char		*gnl_ft_strjoin(char *s1, char const *s2);
char		*gnl_ft_strchr(const char *s, int c);
char		*get_next_line(int fd);

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

void		execute_inst(t_stack *a, t_stack *b, char *inst);
int			is_sorted(t_stack *a);

#endif
