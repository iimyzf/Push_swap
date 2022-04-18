/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:21:03 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_lst_size(*stack_a) < 2)
		return ;
	temp = NULL;
	last = *stack_a;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}
