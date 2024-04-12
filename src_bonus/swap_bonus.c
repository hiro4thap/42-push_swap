/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:30:42 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 17:29:51 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

// do nothing if less than 2 elements.
// ss = sa and sb
void	swap(t_stack *s)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->istk[s->top];
	s->istk[s->top] = s->istk[s->top - 1];
	s->istk[s->top - 1] = tmp;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
