/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_and_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:59 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack **lst)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lst_size(*lst) < 2)
		return ;
	first = *lst;
	last = *lst;
	while (last->next)
		last = last->next;
	*lst = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
