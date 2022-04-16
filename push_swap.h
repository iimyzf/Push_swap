/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:47:52 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/15 01:54:33 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_INT_PLUS_ONE 2147483648

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}   t_list;

t_list  *put_data(int data);
void    add_front(t_list **lst, t_list *newNode);
void    swap_a(t_list **lsta);
void    swap_b(t_list **lstb);
void    swap_a_and_b(t_list **lsta, t_list **lstb);
void    push_a(t_list **lsta, t_list **lstb);
void    push_b(t_list **lsta, t_list **lstb);
void    rotate_a(t_list **lsta);
void    rotate_b(t_list **lstb);
void    rotate_a_and_b(t_list **lsta, t_list **lstb);
void    reverse_rotate_a(t_list **lsta);
void    reverse_rotate_b(t_list **lstb);
void    reverse_rotate_a_and_b(t_list **lsta, t_list **lstb);
void    longest(t_list **lsta, t_list **lstb, int len);
void    rotate_a_to_top(t_list **lst, int index);
void    reverse_rotate_a_to_top(t_list **lst, int size, int index);
void    rotate_b_to_top(t_list **lst, int index);
void    reverse_rotate_b_to_top(t_list **lst, int size, int index);
void    rotate_both_a_and_b(t_list **lsta, t_list **lstb, int index_a, int index_b);
void    reverse_rotate_both_a_and_b(t_list **lsta, t_list **lstb, int index_a, int index_b, int size_a, int size_b);
void    push_those_to_top(t_list **lsta, t_list **lstb, int elema, int elemb);
void	push_from_b_to_a(t_list **lsta, t_list **lstb);
void    push_to_top(t_list **lsta, int data, int size);
void    check_error(int ac, char **av);
void    display_error();
void    three_case(t_list **lsta);
void	four_case(t_list **lsta, t_list **lstb);
void	five_case(t_list **lsta, t_list **lstb);
void    push_to_top_by_index(t_list **lsta, int index);
int     get_the_least_ins(t_list *lsta, t_list *lstb, int elema, int elemb);
int     check_if_sorted(t_list **lst);
int     ft_atoi(char *str);
int     lst_size(t_list *lst);
int	    index_of_max(t_list *lsta);
int	    index_of_min(t_list *lsta);
int     get_index(t_list *lst, int elem);
int     get_the_max_data(t_list *lst);
int     get_the_min_data(t_list *lst);
int     main(int ac, char **av);

#endif