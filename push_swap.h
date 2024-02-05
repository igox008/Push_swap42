/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:43:00 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 18:44:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

int		more_than_one(char *str);
int		arg_count(int ac, char **av);
char	**init_2d(int ac, char **av, int *c);
void	my_exit(int status, char **arr, char *str, t_list *h);
t_list	*parse_and_innit(char **arr);
bool	is_dup(t_list *head);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif