/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:38:37 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 14:08:21 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// shift up to top all elements by 1
void	rotate(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->top < 1)
		return ;
	i = s->top;
	tmp = s->istk[s->top];
	while (0 < i)
	{
		s->istk[i] = s->istk[i - 1];
		i--;
	}
	s->istk[i] = tmp;
	return ;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
