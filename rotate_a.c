/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:00 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:18:04 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_list **lsta)
{
    t_list  *first;
    t_list  *last;

    if (lst_size(*lsta) < 2)
        return ;
    first = *lsta;
    last = *lsta;
    while (last->next)
        last = last->next;
    *lsta = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}