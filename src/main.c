/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:40 by hiono             #+#    #+#             */
/*   Updated: 2024/04/09 18:27:45 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_sa(int ac, char **av)
{
	int		i;
	t_stack	*a;

	a = malloc(1 * sizeof(t_stack));
	a->istack = malloc((ac - 1) * sizeof(int));
	i = 0;
	while (i < ac - 1)
	{
		a->istack[i] = ft_atoi(av[ac - 1 - i]);
		i++;
	}
	a->top = i - 1;
	ft_printf("init a.top:%d\n", a->top);
	return (a);
}

t_stack	*init_sb(int ac)
{
	t_stack	*b;

	b = malloc(1 * sizeof(t_stack));
	b->istack = malloc((ac - 1) * sizeof(int));
	b->top = -1;
	return (b);
}

//TODO:delete before submission
void	test(t_stack *a, t_stack *b)
{
	int i = 0;
	ft_printf("---before operation---\n");
	ft_printf("a->top:%d\n", a->top);
	while (i <= a->top)
	{
		ft_printf("a->istack[%d]:%d\n", i, a->istack[i]);
		i++;
	}
	//swap(a);
	//rotate(a);
	//rrotate(a);
	//push(b, a);
	i = 0;
	ft_printf("---after operation---\n");
	ft_printf("a->top:%d\n", a->top);
	while (i <= a->top)
	{
		ft_printf("a->istack[%d]:%d\n", i, a->istack[i]);
		i++;
	}
	i = 0;
	while (i <= b->top)
	{
		ft_printf("b->istack[%d]:%d\n", i ,b->istack[i]);
		i++;
	}
	(void)b;
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		exit (1);
	if (!is_av_int(ac, av) || !is_unique(ac, av))
	{
		ft_printf("Error\n");
		exit(1);
	}
	a = init_sa(ac, av);
	b = init_sb(ac);
	test(a, b);
	radix_sort(*a, *b);
	free(a);
	free(b);
	return (1);
}
