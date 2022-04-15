/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_the_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:46:19 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/14 22:46:42 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_max(t_list *lsta)
{
	int	max;
	int	index;
	int	index_of_max;

	if (!lsta)
		return (-1);
	index = 0;
	index_of_max = 0;
	max = lsta->data;
	lsta = lsta->next;
	while (lsta)
	{
		index++;
		if (lsta->data > max)
		{
			max = lsta->data;
			index_of_max = index;
		}
		lsta = lsta->next;
	}
	return (index_of_max);
}

int	index_of_min(t_list *lsta)
{
	int	min;
	int	index;
	int	index_of_min;

	if (!lsta)
		return (-1);
	index = 0;
	index_of_min = 0;
	min = lsta->data;
	lsta = lsta->next;
	while (lsta)
	{
		index++;
		if (lsta->data < min)
		{
			min = lsta->data;
			index_of_min = index;
		}
		lsta = lsta->next;
	}
	return (index_of_min);
}

void    push_to_top_by_index(t_list **lsta, int index)
{
    int     size;

    size = lst_size(*lsta);
    if (index >= size)
		return ;
    if (index < size / 2)
    {
        while (index--)
            rotate_a(lsta);
    }
    else
    {
        while (index++ < size)
            reverse_rotate_a(lsta);
    }
}