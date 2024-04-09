/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:33:48 by hiono             #+#    #+#             */
/*   Updated: 2024/04/09 12:28:07 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_str_int(char *str)
{
	int		i;
	char	*istr;

	i = ft_atoi(str);
	istr = ft_itoa(i);
	if (ft_strncmp(str, istr, ft_strlen(str)))
		return (0);
	return (1);
}

static int	is_str_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_av_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_str_digit(av[i]) || !is_str_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_unique(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
