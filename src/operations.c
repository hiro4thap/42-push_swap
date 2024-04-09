/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:27:15 by hiono             #+#    #+#             */
/*   Updated: 2024/04/09 17:47:19 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// swap first 2 elements.
// do nothing if less than 2 elements.
// ss = sa and sb
void	swap(t_stack *s)
{
	int	tmp;

	ft_printf("top when swap:%d\n", s->top);
	if (s->top < 1)
		return ;
	tmp = s->istack[s->top];
	s->istack[s->top] = s->istack[s->top - 1];
	s->istack[s->top - 1] = tmp;
}

// take first element from the other stack and put into the last
// do nothing if the other is empty
void	push(t_stack *s1, t_stack *s2)
{
	if (s2->top < 0)
		return ;
	s1->top++;
	s1->istack[s1->top] = s2->istack[s2->top];
	s2->top--;
}

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
