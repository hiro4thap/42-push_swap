/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:48:48 by hiono             #+#    #+#             */
/*   Updated: 2024/04/13 15:36:54 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	execute_inst(t_stack *a, t_stack *b, char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(inst, "pb\n", 3))
		pb(b, a);
	else if (!ft_strncmp(inst, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(inst, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(inst, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(inst, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(inst, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		rrr(a, b);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->istk[i] < s->istk[i + 1])
			return (0);
		i++;
	}
	return (1);
}
