/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a_and_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:03:02 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (ft_lst_size(*lst) < 2)
		return ;
	temp = *lst;
	next = temp->next;
	temp->next = next->next;
	next->next = temp;
	*lst = next;
}

void	ft_swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		swap(stack_a);
		swap(stack_b);
	}
}
