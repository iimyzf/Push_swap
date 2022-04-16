/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:28:07 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/15 01:35:20 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    is_it_sorted(t_list **lst)
{
    t_list  *temp;
    t_list  *next;

    temp = *lst;
    while (temp && temp->next)
    {
        next = temp->next;
        if (temp->data > next->data)
            return ;
        temp = temp->next;
    }
    exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    t_list  *lsta;
    t_list  *lstb;
    int     i;

    lsta = NULL;
    lstb = NULL;
    if (ac == 1)
        exit(EXIT_FAILURE);
    i = ac - 1;
    while (i > 0)
        add_front(&lsta, put_data(ft_atoi(av[i--])));
    check_error(ac, av);
    is_it_sorted(&lsta);
    if (lst_size(lsta) == 3)
        three_case(&lsta);
    else if (lst_size(lsta) == 5)
        five_case(&lsta, &lstb);
    else
    {
        longest(&lsta, &lstb, lst_size(lsta));
        push_from_b_to_a(&lsta, &lstb);
        push_to_top(&lsta, get_the_min_data(lsta), lst_size(lsta));
    }
    return (0);
}