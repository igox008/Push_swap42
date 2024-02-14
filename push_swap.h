/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:43:00 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/11 18:41:29 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define BG_BLUE "\x1b[44m"

typedef int	t_boolean;
# define FALSE 0
# define TRUE 1

int		more_than_one(char *str);
int		arg_count(int ac, char **av);
char	**init_2d(int ac, char **av, int *c);
void	my_exit(int status, char **arr, char *str, t_list *h);
t_list	*parse_and_innit(char **arr);
bool	is_dup(t_list *head);
int		sa(t_list **stack_a, bool prnt);
int		sb(t_list **stack_b, bool prnt);
void	ss(t_list **stack_a, t_list **stack_b, bool prnt);
int		ra(t_list **stack_a, bool prnt);
int		rb(t_list **stack_b, bool prnt);
void	rr(t_list **stack_a, t_list **stack_b, bool prnt);
int		pa(t_list **stack_a, t_list **stack_b, bool prnt);
int		pb(t_list **stack_a, t_list **stack_b, bool prnt);
int		rra(t_list **stack_a, bool prnt);
int		rrb(t_list **stack_b, bool prnt);
void	rrr(t_list **stack_a, t_list **stack_b, bool prnt);
void	index_it(t_list **head);
void	innit_b(t_list **a, t_list **b);
int		check_sorted(t_list *h);
void	sort_low(t_list **a, t_list **b, int ac);
void	sort_three(t_list **h);
void	go_back_to_a(t_list **a, t_list	**b);
bool	is_in_up(t_list *b, int index);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b, int index);

#endif