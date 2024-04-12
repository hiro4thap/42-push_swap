/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:42:34 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 19:18:49 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

// shift down from top all elements by 1 
void	rrotate(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->top < 1)
		return ;
	i = 0;
	tmp = s->istk[0];
	while (i < s->top)
	{
		s->istk[i] = s->istk[i + 1];
		i++;
	}
	s->istk[i] = tmp;
	return ;
}

void	rra(t_stack *a)
{
	rrotate(a);
}

void	rrb(t_stack *b)
{
	rrotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
}
