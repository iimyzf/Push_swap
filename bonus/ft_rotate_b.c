/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:18:10 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:03:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate_b(t_stack **lstb)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lst_size(*lstb) < 2)
		return ;
	first = *lstb;
	last = *lstb;
	while (last->next)
		last = last->next;
	*lstb = first->next;
	first->next = NULL;
	last->next = first;
}
