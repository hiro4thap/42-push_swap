/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:36:36 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 17:29:42 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->istk[i] < s->istk[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_min_idx(t_stack *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i <= s->top)
	{
		if (s->istk[i] < s->istk[res])
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
		if (s->istk[res] < s->istk[i])
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
	if (value < a->istk[idxa] || a->istk[(idxa + 1) % (a->top + 1)] < value)
		return (idxa);
	i = 0;
	idxa = -1;
	while (i <= a->top)
	{
		if (value < a->istk[i] && (idxa == -1 || a->istk[i] < a->istk[idxa]))
			idxa = i;
		i++;
	}
	return (idxa);
}

// return index of the target (next smaller) value in b
int	get_target_idxb(int value, t_stack *b)
{
	int	idxb;
	int	i;

	idxb = get_max_idx(b);
	if (b->istk[idxb] < value || value < b->istk[(idxb + 1) % (b->top + 1)])
		return (idxb);
	i = 0;
	idxb = -1;
	while (i <= b->top)
	{
		if (b->istk[i] < value && (idxb == -1 || b->istk[idxb] < b->istk[i]))
			idxb = i;
		i++;
	}
	return (idxb);
}
