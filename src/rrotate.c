/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:42:34 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 13:42:36 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// shift down from top all elements by 1 
void	rrotate(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->top < 1)
		return ;
	i = 0;
	tmp = s->istack[0];
	while (i < s->top)
	{
		s->istack[i] = s->istack[i + 1];
		i++;
	}
	s->istack[i] = tmp;
	return ;
}

void	rra(t_stack *a)
{
	rrotate(a);
	ft_printf("rra");
}

void	rrb(t_stack *b)
{
	rrotate(b);
	ft_printf("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr");
}
