/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 01:20:21 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 02:40:23 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isnumeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (! (*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	ft_display_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (ft_isnumeric(av[i]) == 0)
			ft_display_error();
		i++;
	}
	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_display_error();
			j++;
		}
		i++;
	}
}
