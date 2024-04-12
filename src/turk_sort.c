/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:01:33 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 16:12:50 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	turk_sort(t_stack *a, t_stack *b)
{
	t_operation	cheap_op;

	if (a->top == 0 || is_sorted(a))
		return ;
	else if (a->top < 3)
	{
		sort_under_three_asc(a);
		return ;
	}
	pb3(a, b);
	sort_three_desc(b);
	while (2 < a->top)
	{
		cheap_op = get_cheap_op_pb(a, b);
		execute_op(a, b, cheap_op);
		pb(b, a);
	}
	sort_under_three_asc(a);
	while (0 <= b->top)
	{
		cheap_op = get_cheap_op_pa(a, b);
		execute_op(a, b, cheap_op);
		pa(a, b);
	}
	execute_op(a, b, get_op_to_top(a, b, get_min_idx(a), -1));
}
