/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:35:47 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 19:18:11 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

// take first element from the other stack and put into the last
// do nothing if the other is empty
void	push(t_stack *s1, t_stack *s2)
{
	if (s2->top < 0)
		return ;
	s1->top++;
	s1->istk[s1->top] = s2->istk[s2->top];
	s2->top--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
}
