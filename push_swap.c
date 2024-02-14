/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:46:01 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/13 08:19:04 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**init;
	int		arg_count;
	t_list	*stack_a;
	t_list	*stack_b;

	arg_count = 0;
	stack_b = NULL;
	if (ac-- == 1)
		return (0);
	init = init_2d(ac, av, &arg_count);
	stack_a = parse_and_innit(init);
	if (is_dup(stack_a))
		my_exit(1, NULL, "Error", stack_a);
	index_it(&stack_a);
	if (!check_sorted(stack_a))
		my_exit(0, NULL, NULL, stack_a);
	sort_low(&stack_a, &stack_b, arg_count);
	innit_b(&stack_a, &stack_b);
	sort_three(&stack_a);
	go_back_to_a(&stack_a, &stack_b);
	while (check_sorted(stack_a))
		rra(&stack_a, true);
	my_exit(0, NULL, NULL, stack_a);
}
