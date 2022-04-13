/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:40 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:18:43 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_b(t_list **lstb)
{
    t_list  *temp;
    t_list  *next;

    if (lst_size(*lstb) < 2)
        return ;
    temp = *lstb;
    next = temp->next;
    temp->next = next->next;
    next->next = temp;
    *lstb = next;
    write(1, "sa\n", 3);
}