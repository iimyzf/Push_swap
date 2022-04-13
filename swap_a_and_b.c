/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_and_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:03:02 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:18:23 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **lst)
{
    t_list  *temp;
    t_list  *next;

    if (lst_size(*lst) < 2)
        return ;
    temp = *lst;
    next = temp->next;
    temp->next = next->next;
    next->next = temp;
    *lst = next;
}

void    swap_a_and_b(t_list **lsta, t_list **lstb)
{
    if (*lsta && *lstb && (*lsta)->next && (*lstb)->next)
    {
        swap(lsta);
        swap(lstb);
        write(1, "ss\n", 3);
    }
}