/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:11:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 18:42:06 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	int		tmp;

	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = (*stack_a)->n;
		(*stack_a)->n = (*stack_a)->next->n;
		(*stack_a)->next->n = tmp; 
	}
}

void	sb(t_list **stack_b)
{
	int		tmp;

	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp = (*stack_b)->n;
		(*stack_b)->n = (*stack_b)->next->n;
		(*stack_b)->next->n = tmp; 
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack_a) >= 2)
	{
		last = ft_lstlast(*stack_a);
		tmp = (*stack_a)->next;
		last->next = *stack_a;
		(*stack_a)->next = NULL;
		*stack_a = tmp;
	}
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack_b) >= 2)
	{
		last = ft_lstlast(*stack_b);
		tmp = (*stack_b)->next;
		last->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = tmp;
	}
}