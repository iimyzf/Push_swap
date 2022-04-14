/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:17:28 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/12 00:17:38 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_list **lsta, t_list **lstb)
{
    t_list  *temp;

    if (*lstb)
    {
        temp = *lstb;
        *lstb = temp->next;
        temp->next = *lsta;
        *lsta = temp;
        write(1, "pa\n", 3);
    }
}