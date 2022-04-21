/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:14:03 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/18 00:01:40 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	i = 0;
	if (n != 0)
	{
		if (c1[0] == '\0' || c2[0] == '\0')
			return (c1[0] - c2[0]);
		while (i < n && (c1[i] || c2[i]))
		{
			if (c1[i] != c2[i])
				return (c1[i] - c2[i]);
			else
				i++;
		}
	}
	return (0);
}

int	ft_instractions(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		ft_swap_a(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_swap_b(stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		ft_swap_a_and_b(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		ft_push_a(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		ft_push_b(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		ft_rotate_a(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_rotate_b(stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		ft_rotate_a_and_b(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_reverse_rotate_a(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_reverse_rotate_b(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		ft_reverse_rotate_a_and_b(stack_a, stack_b);
	else
		ft_display_error();
	return (1);
}

void	do_instractions(t_stack **stack_a, t_stack **stack_b)
{
	char	*instracs;

	while (1)
	{
		instracs = get_next_line(0);
		if (!instracs)
			break ;
		if (!ft_instractions(stack_a, stack_b, instracs))
			ft_display_error();
		free(instracs);
	}
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *stack;
	while (temp && temp->next)
	{
		next = temp->next;
		if (temp->data > next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(EXIT_FAILURE);
	i = ac - 1;
	while (i > 0)
		ft_add_front(&stack_a, ft_put_data(ft_atoi(av[i--])));
	ft_check_error(ac, av);
	ft_is_sorted(&stack_a);
	do_instractions(&stack_a, &stack_b);
	if (ft_is_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
