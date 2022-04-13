/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:32 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:18:35 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_list **lsta)
{
    t_list  *temp;
    t_list  *next;

    if (lst_size(*lsta) < 2)
        return ;
    temp = *lsta;
    next = temp->next;
    temp->next = next->next;
    next->next = temp;
    *lsta = next;
    write(1, "sa\n", 3);
}