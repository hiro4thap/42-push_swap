/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:01:33 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 21:05:43 by hiono            ###   ########.fr       */
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

int	get_idx_min(t_stack *a)
{
	int	i;

	i = a->top;
	while (0 < i)
	{
		if(a->istack[i - 1] < a->istack[i])
			return (i);
		i--;
	}
	return (i);
}

// return index of the target (next bigger) value in a
int	get_idxa(int value, t_stack *a)
{
	int	idxa;
	int	i;

	idxa = get_idx_min(a);
	if (a->istack[idxa] < value || value < a->istack[(idxa - 1) % (a->top + 1)])
		return (idxa);
	i = a->top;
	idxa = -1;
	while (0 <= i)
	{
		if (value < a->istack[i] && 0 < idxa)
			return (idxa);
		if (a->istack[i] < value)
			idxa = i;
		i--;
	}
	//ft_printf("value: %d idxa:%d\n", value, idxa);
	return (idxa);
}

int	get_idx_max(t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->top)
	{
		if(b->istack[i + 1] < b->istack[i])
			return (i);
		i++;
	}
	return (i);
}

// return index of the target (next smaller) value in b
int	get_idxb(int value, t_stack *b)
{
	int	idxb;
	int	i;

	idxb = get_idx_max(b);
	if (b->istack[idxb] < value || value < b->istack[(idxb + 1) % (b->top + 1)])
		return (idxb);
	i = 0;
	idxb = -1;
	while (i <= b->top)
	{
		if (value < b->istack[i] && 0 < idxb)
			return (idxb);
		if (b->istack[i] < value)
			idxb = i;
		i++;
	}
	//ft_printf("value: %d idxb:%d\n", value, idxb);
	return (idxb);
}

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

t_operation	get_cheap_op(t_stack *a, t_stack *b)
{
	t_operation	cheap_op;
	t_operation	tmp;
	int			idxa;
	int			idxb;

	idxa = a->top;
	while (0 <= idxa)
	{
		idxb = get_idxb(a->istack[idxa], b);
		tmp = get_op(a, b, idxa, idxb);
		//ft_printf("ra:%d rra:%d rb:%d rrb:%d sum:%d\n", tmp.c_ra, tmp.c_rra, tmp.c_rb, tmp.c_rrb, tmp.c_sum);
		if (idxa == a->top || tmp.c_sum < cheap_op.c_sum)
			cheap_op = tmp;
		idxa--;
	}
	return (cheap_op);
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
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_operation	cheap_op;

	if (a->top == 0)
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
		cheap_op = get_cheap_op(a, b);
		//ft_printf("cheap ra:%d rra:%d rb:%d rrb:%d\n", cheap_op.c_ra, cheap_op.c_rra, cheap_op.c_rb, cheap_op.c_rrb);
		execute_op(a, b, cheap_op);
		pb(b, a);
	}
	//TODO:handle the case where numebr of input 3~5
	sort_three_asc(a);
	while (0 <= b->top)
	{
		cheap_op = get_cheap_op(b, a);
		execute_op(a, b, cheap_op);
		pa(a, b);
	}
}
