/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 05:34:03 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/13 05:17:48 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_in(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_w(char const *s, char *c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (is_in(s[i], c))
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] && !is_in(s[i], c))
			i++;
	}
	return (cnt);
}

int	arg_count(int ac, char **av)
{
	int	i;
	int	count;

	(1) && (i = 0, count = 0);
	while (i < ac)
	{
		count += count_w(av[i], " ");
		i++;
	}
	return (count);
}

void	my_exit(int status, char **arr, char *str, t_list *h)
{
	int	i;

	i = 0;
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	if (h != NULL)
		ft_lstclear(&h, NULL);
	if (status != -1)
		exit(status);
}
