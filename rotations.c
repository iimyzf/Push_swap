/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:21:06 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/15 01:43:33 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a_to_top(t_list **lst, int index)
{
    while (index > 0)
    {
        rotate_a(lst);
        index--;
    }
}

void    rotate_b_to_top(t_list **lst, int index)
{
    while (index > 0)
    {
        rotate_b(lst);
        index--;
    }
}

void    rotate_both_a_and_b(t_list **lsta, t_list **lstb, int index_a, int index_b)
{
    while (index_a > 0 && index_b > 0)
    {
        rotate_a_and_b(lsta, lstb);
        index_a--;
        index_b--;
    }
    while (index_a > 0)
    {
        rotate_a(lsta);
        index_a--;
    }
    while (index_b > 0)
    {
        rotate_b(lstb);
        index_b--;
    }
}