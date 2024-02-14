/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:34:03 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/11 07:55:47 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

int	do_move(t_list **a, t_list **b, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		return (sa(a, false), 1);
	else if (!ft_strncmp(move, "sb\n", 3))
		return (sb(b, false), 1);
	else if (!ft_strncmp(move, "ra\n", 3))
		return (ra(a, false), 1);
	else if (!ft_strncmp(move, "rb\n", 3))
		return (rb(b, false), 1);
	else if (!ft_strncmp(move, "ss\n", 3))
		return (ss(a, b, false), 1);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (rr(a, b, false), 1);
	else if (!ft_strncmp(move, "pa\n", 3))
		return (pa(a, b, false), 1);
	else if (!ft_strncmp(move, "pb\n", 3))
		return (pb(a, b, false), 1);
	else if (!ft_strncmp(move, "rra\n", 4))
		return (rra(a, false), 1);
	else if (!ft_strncmp(move, "rrb\n", 4))
		return (rrb(b, false), 1);
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (rrr(a, b, false), 1);
	return (0);
}

int	check_move(char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(move, "sb\n", 3))
		return (1);
	else if (!ft_strncmp(move, "ra\n", 3))
		return (1);
	else if (!ft_strncmp(move, "rb\n", 3))
		return (1);
	else if (!ft_strncmp(move, "ss\n", 3))
		return (1);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (1);
	else if (!ft_strncmp(move, "pa\n", 3))
		return (1);
	else if (!ft_strncmp(move, "pb\n", 3))
		return (1);
	else if (!ft_strncmp(move, "rra\n", 4))
		return (1);
	else if (!ft_strncmp(move, "rrb\n", 4))
		return (1);
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (1);
	return (0);
}

void	read_loop(t_moves **m, t_list **a)
{
	char	*move;
	t_moves	*cur;

	move = get_next_line(0);
	cur = NULL;
	while (1)
	{
		if (!move)
			break ;
		if (!check_move(move))
		{
			ft_move_clear(m);
			my_exit(1, NULL, "Error", *a);
		}
		cur = ft_newmove(move);
		ft_addmove(m, cur);
		move = get_next_line(0);
	}
}

void	aplly_moves(t_list **a, t_list **b, t_moves **m)
{
	t_moves	*tmp;

	tmp = *m;
	while (tmp)
	{
		do_move(a, b, tmp->move);
		tmp = tmp->next;
	}
	ft_move_clear(m);
}

int	main(int ac, char **av)
{
	char	**init;
	int		arg_count;
	t_list	*stack_a;
	t_list	*stack_b;
	t_moves	*moves;

	if (ac-- == 1)
		return (0);
	(1) && (arg_count = 0, stack_b = NULL, init = init_2d(ac, av, &arg_count));
	(1) && (stack_a = parse_and_innit(init), moves = NULL);
	if (is_dup(stack_a))
		my_exit(1, NULL, "Error", stack_a);
	index_it(&stack_a);
	read_loop(&moves, &stack_a);
	aplly_moves(&stack_a, &stack_b, &moves);
	if (!check_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		free_and_exit(&stack_a, &stack_b, "OK");
	else
		free_and_exit(&stack_a, &stack_b, "KO");
	return (0);
}
