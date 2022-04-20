/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:40 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_b(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*next;

	if (ft_lst_size(*stack_b) < 2)
		return ;
	temp = *stack_b;
	next = temp->next;
	temp->next = next->next;
	next->next = temp;
	*stack_b = next;
}
