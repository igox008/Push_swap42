/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:20:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 17:29:10 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		ft_lstadd_front(stack_a, *stack_b);
		ft_lstdelone(*stack_b, NULL);
		*stack_b = tmp;
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		ft_lstdelone(*stack_a, NULL);
		*stack_a = tmp;
	}
}