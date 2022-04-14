/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_sub.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:56:42 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/13 00:33:12 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(int *array, int len)
{
    int i;
    int max_value;

    i = 1;
    max_value = array[0];
    while (i < len)
    {
        if (max_value < array[i])
            max_value = array[i];
        i++;
    }
    return (max_value);
}

int check_if_num_is_in_array(int *array, int len, int num)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (array[i] == num)
            return (1);
        i++;
    }
    return (0);
}

void    get_the_lis(int *numbers, int *lis, t_list **node, int len)
{
    int i;
    int j;

    i = 0;
    while (*node)
    {
        numbers[i] = (*node)->data;
        lis[i] = 1;
        i++;
        *node = (*node)->next;
    }
    i = 1;
    while (i < len)
    {
        j = 0;
        while (j < i)
        {
            if (numbers[i] > numbers[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
            j++;
        }
        i++;
    }
}

int *get_the_final_lis(int *numbers, int *lis, int len)
{
    int i;
    int j;
    int *final_lis;

    final_lis = malloc(sizeof(int) * find_max(lis, len));
    j = find_max(lis, len);
    i = len;
    while (i > 0)
    {
        i--;
        if (lis[i] == j)
        {
            j--;
            final_lis[j] = numbers[i];
        }
    }
    return (final_lis);
}

void    longest(t_list **lsta, t_list **lstb, int len)
{
    int i;
    int *numbers;
    int *lis;
    int *final_lis;
    t_list  *node;

    numbers = malloc(sizeof(int) * len);
    lis = malloc(sizeof(int) * len);
    node = *lsta;
    get_the_lis(numbers, lis, &node, len);
    final_lis = get_the_final_lis(numbers, lis, len);
    i = 0;
    while (i < len)
    {
        node = *lsta;
        if (check_if_num_is_in_array(final_lis, find_max(lis, len), node->data))
            rotate_a(lsta);
        else
            push_b(lsta, lstb);
        i++;
    }
    free(numbers);
    free(lis);
    free(final_lis);
}