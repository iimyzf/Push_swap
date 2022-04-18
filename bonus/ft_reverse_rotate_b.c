/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:24:02 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_rotate_b(t_stack **lstb)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_lst_size(*lstb) < 2)
		return ;
	temp = NULL;
	last = *lstb;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *lstb;
	*lstb = last;
}
