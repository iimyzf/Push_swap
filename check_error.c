/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:27:51 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/15 01:24:57 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


void    display_error()
{
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}

void    check_error(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        if (ft_isnumeric(av[i]) == 0)
            display_error();
        i++;
    }
    i = 1;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                display_error();
            j++;
        }
        i++;
    }
}