/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:25:22 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/13 05:10:43 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

int	is_dup_sign(char *s, char c)
{
	char		*begin;
	char		*last;

	if ((s[0] == '+' || s[0] == '-') && (!s[1] || !ft_isdigit(s[1])))
		return (TRUE);
	begin = ft_strchr((const char *)s, c);
	last = ft_strrchr((const char *)s, c);
	if (!begin || !last)
		return (FALSE);
	if ((ft_strlen(begin) != ft_strlen(last))
		|| (ft_strchr((const char *)s, '+')
			&& ft_strchr((const char *)s, '-'))
		|| ft_strlen(begin) != ft_strlen(s))
		return (TRUE);
	return (FALSE);
}

bool	is_dup(t_list *head)
{
	t_list	*cur;
	t_list	*tmp;

	cur = head;
	while (cur != NULL)
	{
		tmp = cur->next;
		while (tmp != NULL)
		{
			if (cur->n == tmp->n)
				return (true);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (false);
}

t_list	*parse_and_innit(char **arr)
{
	t_list	*head;
	t_list	*cur;
	int		i;
	long	n;

	i = 0;
	head = NULL;
	while (arr[i])
	{
		if (is_dup_sign(arr[i], '+') || is_dup_sign(arr[i], '-'))
			my_exit(1, arr, "Error", head);
		n = ft_atoi(arr[i]);
		if (n == -2147483649)
			my_exit(1, arr, "Error", head);
		cur = ft_lstnew(n, -1);
		if (!cur)
			my_exit(1, arr, "Error", head);
		ft_lstadd_back(&head, cur);
		i++;
	}
	my_exit(-1, arr, NULL, NULL);
	return (head);
}
