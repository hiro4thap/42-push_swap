/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:36:36 by hiono             #+#    #+#             */
/*   Updated: 2024/04/11 17:48:20 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min_idx(t_stack *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i <= s->top)
	{
		if(s->istack[i] < s->istack[res])
			res = i;
		i++;
	}
	return (res);
}

int	get_max_idx(t_stack *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i <= s->top)
	{
		if(s->istack[res] < s->istack[i])
			res = i;
		i++;
	}
	return (res);
}

// return index of the target (next bigger) value in a
int	get_target_idxa(int value, t_stack *a)
{
	int	idxa;
	int	i;

	idxa = get_min_idx(a);
	if (value < a->istack[idxa] || a->istack[(idxa + 1) % (a->top + 1)] < value)
		return (idxa);
	i = 0;
	idxa = -1;
	while (i <= a->top)
	{
		if (value < a->istack[i] && (idxa == -1 || a->istack[i] < a->istack[idxa]))
			idxa = i;
		i++;
	}
	//ft_printf("value: %d idxa:%d\n", value, idxa);
	return (idxa);
}

// return index of the target (next smaller) value in b
int	get_target_idxb(int value, t_stack *b)
{
	int	idxb;
	int	i;

	idxb = get_max_idx(b);
	if (b->istack[idxb] < value || value < b->istack[(idxb + 1) % (b->top + 1)])
		return (idxb);
	i = 0;
	idxb = -1;
	while (i <= b->top)
	{
		if (b->istack[i] < value && (idxb == -1 || b->istack[idxb] < b->istack[i]))
			idxb = i;
		i++;
	}
	return (idxb);
}
