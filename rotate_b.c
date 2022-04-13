/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:10 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:18:14 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_b(t_list **lstb)
{
    t_list  *first;
    t_list  *last;

    if (lst_size(*lstb) < 2)
        return ;
    first = *lstb;
    last = *lstb;
    while (last->next)
        last = last->next;
    *lstb = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}