/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:48:48 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 16:12:58 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two_asc(t_stack *a)
{
	if (a->istk[0] < a->istk[1])
		sa(a);
}

void	pb3(t_stack *a, t_stack *b)
{
	pb(b, a);
	pb(b, a);
	pb(b, a);
}

void	sort_under_three_asc(t_stack *a)
{
	if (a->top < 1)
		return ;
	else if (a->top == 1)
	{
		sort_two_asc(a);
		return ;
	}
	if (a->istk[0] < a->istk[1] && a->istk[2] < a->istk[1])
		rra(a);
	else if (a->istk[0] < a->istk[2] && a->istk[1] < a->istk[2])
		ra(a);
	if (a->istk[1] < a->istk[2])
		sa(a);
}

void	sort_three_desc(t_stack *b)
{
	if (b->istk[1] < b->istk[0] && b->istk[1] < b->istk[2])
		rrb(b);
	else if (b->istk[2] < b->istk[0] && b->istk[2] < b->istk[1])
		rb(b);
	if (b->istk[2] < b->istk[1])
		sb(b);
}
