/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_and_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:26:06 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:27:32 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_list **lst)
{
    t_list  *temp;
    t_list  *last;

    if (lst_size(*lst) < 2)
        return ;
    temp = NULL;
    last = *lst;
    while (last->next)
    {
        temp = last;
        last = last->next;
    }
    temp->next = NULL;
    last->next = *lst;
    *lst = last;
}

void    reverse_rotate_a_and_b(t_list **lsta, t_list **lstb)
{
    if (*lsta && *lstb && (*lsta)->next && (*lstb)->next)
    {
        reverse_rotate(lsta);
        reverse_rotate(lstb);
        write(1, "rrr\n", 4);
    }
}