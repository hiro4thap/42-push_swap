/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:25:54 by hiono             #+#    #+#             */
/*   Updated: 2024/04/11 18:31:29 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_operation	get_op(t_stack *a, t_stack *b, int idxa, int idxb)
{
	t_operation	op;

	op.c_ra = 0;
	op.c_rra = 0;
	op.c_rb = 0;
	op.c_rrb = 0;
	if (a->top / 2 <= idxa)
		op.c_ra = a->top - idxa;
	else
		op.c_rra = idxa + 1;
	if (b->top / 2 <= idxb)
		op.c_rb = b->top - idxb;
	else
		op.c_rrb = idxb + 1;
	op.c_sum = op.c_ra + op.c_rra + op.c_rb + op.c_rrb;
	return (op);
}	

t_operation	get_cheap_op_pb(t_stack *a, t_stack *b)
{
	t_operation	cheap_op;
	t_operation	tmp;
	int			idxa;
	int			idxb;

	idxa = 0;
	while (idxa <= a->top)
	{
		idxb = get_target_idxb(a->istack[idxa], b);
		tmp = get_op(a, b, idxa, idxb);
		if (idxa == 0 || tmp.c_sum < cheap_op.c_sum)
			cheap_op = tmp;
		idxa++;
	}
	return (cheap_op);
}

t_operation	get_cheap_op_pa(t_stack *a, t_stack *b)
{
	t_operation	cheap_op;
	t_operation	tmp;
	int			idxa;
	int			idxb;

	idxb = 0;
	while (idxb <= b->top)
	{
		idxa = get_target_idxa(b->istack[idxb], a);
		tmp = get_op(a, b, idxa, idxb);
		if (idxb == 0 || tmp.c_sum < cheap_op.c_sum)
			cheap_op = tmp;
		idxb++;
	}
	return (cheap_op);
}

void	execute_op(t_stack *a, t_stack *b, t_operation op)
{
	while (0 < op.c_ra && 0 < op.c_rb)
	{
		rr(a, b);
		op.c_ra--;
		op.c_rb--;
	}
	while (0 < op.c_rra && 0 < op.c_rrb)
	{
		rrr(a, b);
		op.c_rra--;
		op.c_rrb--;
	}
	while (0 < op.c_ra--)
		ra(a);
	while (0 < op.c_rra--)
		rra(a);
	while (0 < op.c_rb--)
		rb(b);
	while (0 < op.c_rrb--)
		rrb(b);
}
