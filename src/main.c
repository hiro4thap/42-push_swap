/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:40 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 15:12:55 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_sa(int len, char **av)
{
	int		i;
	t_stack	*a;

	a = malloc(1 * sizeof(t_stack));
	a->istack = malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		a->istack[i] = ft_atoi(av[len - 1 - i]);
		i++;
	}
	a->top = i - 1;
	ft_printf("init a.top:%d\n", a->top);
	return (a);
}

t_stack	*init_sb(int len)
{
	t_stack	*b;

	b = malloc(1 * sizeof(t_stack));
	b->istack = malloc(len * sizeof(int));
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

int	get_ac(char **args)
{
	int	i;

	i = 1;
	while (*args)
	{
		args++;
		i++;
	}
	return (i);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (ac == 1)
		exit (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		ac = get_ac(args);
	}
	else
		args = &av[1]; 
	if (!is_args_int(ac - 1, args) || !is_args_unique(ac - 1, args))
	{
		ft_printf("Error\n");
		exit(1);
	}
	a = init_sa(ac - 1, args);
	b = init_sb(ac - 1);
	test(a, b);
	turk_sort(*a, *b);
	free(a);
	free(b);
	if (ac == 2)
		free(args);
	return (1);
}
