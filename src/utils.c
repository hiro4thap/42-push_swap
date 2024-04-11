/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:48:48 by hiono             #+#    #+#             */
/*   Updated: 2024/04/11 18:28:44 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two_asc(t_stack *a)
{
	if (a->istack[0] < a->istack[1])
		sa(a);
}

void	pb3(t_stack *a, t_stack *b)
{
	pb(b, a);
	pb(b, a);
	pb(b, a);
}

void	sort_three_asc(t_stack *a)
{
	if (a->istack[0] < a->istack[1] && a->istack[2] < a->istack[1])
		rra(a);
	else if (a->istack[0] < a->istack[2] && a->istack[1] < a->istack[2])
		ra(a);
	if (a->istack[1] < a->istack[2])
		sa(a);
}

void	sort_three_desc(t_stack *b)
{
	if (b->istack[1] < b->istack[0] && b->istack[1] < b->istack[2])
		rrb(b);
	else if (b->istack[2] < b->istack[0] && b->istack[2] < b->istack[1])
		rb(b);
	if (b->istack[2] < b->istack[1])
		sb(b);
}

