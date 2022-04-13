/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:24:02 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:25:37 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate_b(t_list **lstb)
{
    t_list  *temp;
    t_list  *last;

    if (lst_size(*lstb) < 2)
        return ;
    temp = NULL;
    last = *lstb;
    while (last->next)
    {
        temp = last;
        last = last->next;
    }
    temp->next = NULL;
    last->next = *lstb;
    *lstb = last;
    write(1, "rrb\n", 4);
}