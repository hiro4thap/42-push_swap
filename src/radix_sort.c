/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:01:33 by hiono             #+#    #+#             */
/*   Updated: 2024/04/09 17:50:38 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_maxdiv(int *s, int len)
{
	int	div;
	int	i;

	div = 1;
	while (1)
	{
		i = 0;
		while (-10 < s[i] / div && s[i] / div < 10 && i < len)
		{
			i++;
		}
		if (i == len)
			return (div);
		div *= 10;
	}
}

void	radix_sort(t_stack a, t_stack b)
{
	int	max_div;

	max_div = get_maxdiv(a.istack, a.top + 1);
	ft_printf("max_div:%d\n", max_div);
	(void)b;
}
