/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:38:37 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 13:40:20 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// shift up to top all elements by 1
void	rotate(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->top < 1)
		return ;
	i = s->top;
	tmp = s->istack[s->top];
	while (0 < i)
	{
		s->istack[i] = s->istack[i - 1];
		i--;
	}
	s->istack[i] = tmp;
	return ;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr");
}
