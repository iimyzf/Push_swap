/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 03:21:37 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/14 22:46:40 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_case(t_list **lsta)
{
    int index;

    index = index_of_max(*lsta);
    if (index == 2)
    {
        if (!check_if_sorted(lsta))
            swap_a(lsta);
    }
    else if (index == 1)
    {
        reverse_rotate_a(lsta);
        if (!check_if_sorted(lsta))
            swap_a(lsta);
    }
    else if (index == 0)
    {
        rotate_a(lsta);
        if (!check_if_sorted(lsta))
            swap_a(lsta);
    }
}

void	four_case(t_list **lsta, t_list **lstb)
{
	int	index;

	index = index_of_min(*lsta);
	push_to_top_by_index(lsta, index);
	push_b(lsta, lstb);
	three_case(lsta);
	push_a(lsta, lstb);
}

void	five_case(t_list **lsta, t_list **lstb)
{
	int	index;

	index = index_of_min(*lsta);
	push_to_top_by_index(lsta, index);
	push_b(lsta, lstb);
	four_case(lsta, lstb);
	push_a(lsta, lstb);
}