/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:20:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/11 07:56:32 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

int	pa(t_list **stack_a, t_list **stack_b, bool prnt)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		if (*stack_a)
			ft_lstadd_front(stack_a, tmp);
		else
			*stack_a = tmp;
	}
	if (prnt)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b, bool prnt)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		if (*stack_b)
			ft_lstadd_front(stack_b, tmp);
		else
			*stack_b = tmp;
	}
	if (prnt)
		ft_printf("pb\n");
	return (1);
}
