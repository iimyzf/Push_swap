/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:45:36 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/15 00:44:48 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_the_max_data(t_list *lst)
{
    int max;

    max = lst->data;
    while (lst)
    {
        if (lst->data > max)
            max = lst->data;
        lst = lst->next;
    }
    return (max);
}

int get_the_min_data(t_list *lst)
{
    int min;

    min = lst->data;
    while (lst)
    {
        if (lst->data < min)
            min = lst->data;
        lst = lst->next;
    }
    return (min);
}

int get_the_greater_than_this_number(t_list *lst, int num)
{
    t_list  *temp;

    temp = lst;
    while (lst->next)
    {
        if (num > lst->data && num < lst->next->data)
            return (lst->next->data);
        lst = lst->next;
    }
    if (num > lst->data && num < temp->data)
        return (temp->data);
    return (get_the_min_data(temp));
}

void	find_the_best_element(t_list *lsta, t_list *lstb, int *elema, int *elemb)
{
	t_list	*node_b;
	int		min_ins;
	int		total_ins;
	int		data_a;
	int		data_b;

	min_ins = 100000;
	node_b = lstb;
	while (node_b)
	{
        data_b = node_b->data;
		data_a = get_the_greater_than_this_number(lsta, data_b);
		total_ins = get_the_least_ins(lsta, lstb, data_a, data_b);
		if (total_ins < min_ins)
		{
			min_ins = total_ins;
			*elema = data_a;
			*elemb = data_b;
		}
		node_b = node_b->next;
	}
}

void	push_from_b_to_a(t_list **lsta, t_list **lstb)
{
	int	elema;
	int	elemb;

	elema = 0;
	elemb = 0;
	while (*lstb)
	{
		find_the_best_element(*lsta, *lstb, &elema, &elemb);
		push_those_to_top(lsta, lstb, elema, elemb);
		push_a(lsta, lstb);
	}
}