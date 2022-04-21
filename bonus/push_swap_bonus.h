/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:14:34 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/16 03:09:58 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_INT_PLUS_ONE 2147483648

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read_file(int fd, char *buffer);
char	*ft_which_case(int fd, char *buffer);
t_stack	*ft_put_data(int data);
size_t	ft_strlen(const char *s);
void	ft_add_front(t_stack **lst, t_stack *new_node);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	ft_switch_left(char *buffer);
void	ft_bzero(void *s, size_t n);
void	ft_display_error(void);
void	ft_check_error(int ac, char **av);
int		ft_instructions(t_stack **stack_a, t_stack **stack_b, char *str);
int		ft_is_sorted(t_stack **stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_newline_inbuffer(char *buffer);
int		ft_atoi(char *str);
int		ft_lst_size(t_stack *lst);

#endif
