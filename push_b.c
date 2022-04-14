/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:17:49 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:17:52 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_b(t_list **lsta, t_list **lstb)
{
    t_list  *temp;

    if (*lsta)
    {
        temp = *lsta;
        *lsta = temp->next;
        temp->next = *lstb;
        *lstb = temp;
        write(1, "pb\n", 3);
    }
}