/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_least_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:03:07 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/13 22:54:14 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max(int x, int y)
{
    if (x > y)
        return (x);
    return (y);
}

int get_index(t_list *lst, int elem)
{
    int index;

    index = 0;
    while (lst)
    {
        if (lst->data == elem)
            return (index);
        index++;
        lst = lst->next;
    }
    return (index);
}

int get_the_least_ins(t_list *lsta, t_list *lstb, int elema, int elemb)
{
    int size_a;
    int size_b;
    int index_a;
    int index_b;

    size_a = lst_size(lsta);
    size_b = lst_size(lstb);
    index_a = get_index(lsta, elema);
    index_b = get_index(lstb, elemb);
    if (index_a <= size_a / 2 && index_b <= size_b / 2)
        return (get_max(index_a, index_b)); 
    else if (index_a > size_a /2 && index_b > size_b / 2)
        return (get_max(size_a - index_a, size_b - index_b));
    else
    {
        if (index_a <= size_a / 2)
            return (index_a + (size_b - index_b));
        else
            return (index_b + (size_a - index_a));
    }
    return (-1);
}

void    push_those_to_top(t_list **lsta, t_list **lstb, int elema, int elemb)
{
    int size_a;
    int size_b;
    int index_a;
    int index_b;

    size_a = lst_size(*lsta);
    size_b = lst_size(*lstb);
    index_a = get_index(*lsta, elema);
    index_b = get_index(*lstb, elemb);
    if (index_a <= size_a / 2 && index_b <= size_b / 2)
        rotate_both_a_and_b(lsta, lstb, index_a, index_b);
    else if (index_a > size_a /2 && index_b > size_b / 2)
        reverse_rotate_both_a_and_b(lsta, lstb, index_a, index_b, size_a, size_b);
    else
    {
        if (index_a <= size_a / 2)
        {
            rotate_a_to_top(lsta, index_a);
            reverse_rotate_b_to_top(lstb, size_b, index_b);
        }
        else
        {
            rotate_b_to_top(lstb, index_b);
            reverse_rotate_a_to_top(lsta, size_a, index_a);
        }
    }
}

void    push_to_top(t_list **lsta, int data, int size)
{
    t_list  *temp;
    int     index;

    index = 0;
    temp = *lsta;
    while (temp)
    {
        if (temp->data == data)
            break;
        index++;
        temp = temp->next;
    }
    if (index < size / 2)
    {
        while (index--)
            rotate_a(lsta);
    }
    else
    {
        while (index++ < size)
            reverse_rotate_a(lsta);
    }
}