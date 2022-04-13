/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:21:03 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:23:47 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate_a(t_list **lsta)
{
    t_list  *temp;
    t_list  *last;

    if (lst_size(*lsta) < 2)
        return ;
    temp = NULL;
    last = *lsta;
    while (last->next)
    {
        temp = last;
        last = last->next;
    }
    temp->next = NULL;
    last->next = *lsta;
    *lsta = last;
    write(1, "rra\n", 4);
}