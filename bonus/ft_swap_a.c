/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:32 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_a(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*next;

	if (ft_lst_size(*stack_a) < 2)
		return ;
	temp = *stack_a;
	next = temp->next;
	temp->next = next->next;
	next->next = temp;
	*stack_a = next;
}
