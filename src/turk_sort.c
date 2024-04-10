/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:01:33 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 17:38:46 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted_asc(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->istack[i] < s->istack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_dsc(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->istack[i] > s->istack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_two_asc(t_stack *a)
{
	if (!is_sorted_asc(a))
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

void	execute_op(t_stack *a, t_stack *b, t_operation op)
{
	while (0 < op.c_ra--)
		ra(a);
	while (0 < op.c_rra--)
		rra(a);
	while (0 < op.c_rb--)
		rb(b);
	while (0 < op.c_rrb--)
		rrb(b);
	pb(b, a);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_operations	tmp;
	t_operations	min;

	if (a->top == 0)
		return;
	else if (a->top == 1)
	{
		sort_two_asc(a);
		return ;
	}
	pb3(a, b);
	sort_three_desc(b);
	while (3 < a->top)
	{
		cheap_op = calculate op(a, b);
		execute_op(a, b, cheap_op);
	}
	pa(a, b);
	pa(a, b);
	pa(a, b);
	(void)a;
	(void)b;
}
