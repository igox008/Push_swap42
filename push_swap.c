/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:46:01 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 23:17:15 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	v(){system("leaks push_swap");}

int	main(int ac, char **av)
{
	char	**init;
	int		arg_count;
	t_list	*stack_a;

	// atexit(v);
	arg_count = 0;
	if (ac-- == 1)
		return (ft_printf(RED"Invalid input\n"RESET), -1);
	init = init_2d(ac, av, &arg_count);
	stack_a = parse_and_innit(init);
	if (is_dup(stack_a))
		my_exit(1, NULL, "Duplicate error", stack_a);
	// my_exit(-1, NULL, NULL, stack_a);
	sa(&stack_a);
	while (stack_a != NULL)
	{
		ft_printf("[%d]\n", stack_a->n);
		stack_a = stack_a->next;
	}
}
