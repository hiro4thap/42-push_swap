/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:39:22 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 17:29:44 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_stack	*init_sa(int len, char **av)
{
	int		i;
	t_stack	*a;

	a = malloc(1 * sizeof(t_stack));
	a->istk = malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		a->istk[i] = ft_atoi(av[len - 1 - i]);
		i++;
	}
	a->top = i - 1;
	return (a);
}

t_stack	*init_sb(int len)
{
	t_stack	*b;

	b = malloc(1 * sizeof(t_stack));
	b->istk = malloc(len * sizeof(int));
	b->top = -1;
	return (b);
}
