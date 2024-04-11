/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:01:33 by hiono             #+#    #+#             */
/*   Updated: 2024/04/11 18:57:56 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	turk_sort(t_stack *a, t_stack *b)
{
	t_operation	cheap_op;

	if (a->top == 0) //TODO:add is_sorted and done nothing
		return;
	else if (a->top == 1)
	{
		sort_two_asc(a);
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
	//TODO:handle the case where numebr of input 3~5
	sort_three_asc(a);
	while (0 <= b->top)
	{
		cheap_op = get_cheap_op_pa(a, b);
		execute_op(a, b, cheap_op);
		pa(a, b);
	}
	execute_op(a, b ,get_op(a, b, get_min_idx(a), -1));
}
