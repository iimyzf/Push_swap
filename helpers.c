/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:52:39 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/14 04:00:13 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *str)
{
    int                 i;
    int                 sign;
    unsigned long long  res;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        res = res * 10 + (str[i++] - 48);
        if ((res > MAX_INT && sign > 0) || (res > MAX_INT_PLUS_ONE && sign < 0))
            display_error();
    }
    return (res * sign);
}

int lst_size(t_list *lst)
{
    int len;

    len = 0;
    while (lst)
    {
        len++;
        lst = lst->next;
    }
    return (len);
}

t_list  *put_data(int data)
{
    t_list  *newNode;

    newNode = (t_list *)malloc(sizeof(t_list));
    if (!newNode)
        return (NULL);
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

void    add_front(t_list **lst, t_list *newNode)
{
    if (!*lst)
    {
        *lst = newNode;
        return ;
    }
    newNode->next = *lst;
    *lst = newNode;
}

int check_if_sorted(t_list **lst)
{
    t_list  *temp;
    t_list  *next;

    temp = *lst;
    while (temp && temp->next)
    {
        next = temp->next;
        if (temp->data > next->data)
            return (0);
        temp = temp->next;
    }
    return (1);
}