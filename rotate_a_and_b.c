/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_and_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:59 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:19:06 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_list **lst)
{
    t_list  *first;
    t_list  *last;

    if (lst_size(*lst) < 2)
        return ;
    first = *lst;
    last = *lst;
    while (last->next)
        last = last->next;
    *lst = first->next;
    first->next = NULL;
    last->next = first;
}

void    rotate_a_and_b(t_list **lsta, t_list **lstb)
{
    if (*lsta && *lstb && (*lsta)->next && (*lstb)->next)
    {
        rotate(lsta);
        rotate(lstb);
        write(1, "rr\n", 3);
    }
}