/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:11:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/09 08:56:29 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_list **stack_a, bool prnt)
{
	t_list	*tmp;
	t_list	*nxt;

	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = *stack_a;
		nxt = (*stack_a)->next;
		tmp->next = nxt->next;
		nxt->next = tmp;
		*stack_a = nxt;
		if (prnt)
			ft_printf("sa\n");
		return (0);
	}
	return (1);
}

int	sb(t_list **stack_b, bool prnt)
{
	t_list	*tmp;
	t_list	*nxt;

	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp = *stack_b;
		nxt = (*stack_b)->next;
		tmp->next = nxt->next;
		nxt->next = tmp;
		*stack_b = nxt;
		if (prnt)
			ft_printf("sa\n");
		return (0);
	}
	return (1);
}

void	ss(t_list **stack_a, t_list **stack_b, bool prnt)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (prnt)
		ft_printf("ss\n");
}

int	ra(t_list **stack_a, bool prnt)
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
		if (prnt)
			ft_printf("ra\n");
		return (0);
	}
	return (1);
}

int	rb(t_list **stack_b, bool prnt)
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
		if (prnt)
			ft_printf("rb\n");
		return (0);
	}
	return (1);
}
