/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:40:20 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/13 05:20:35 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
	{
		ft_putstr_fd("Error\n", 2);
		return (FALSE);
	}
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isdigit(str[i])
			&& str[i] != '-' && str[i] != '+')
		{
			ft_putstr_fd("Error\n", 2);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	more_than_one(char *str)
{
	int	i;

	i = 0;
	if (!is_valid(str))
		exit(1);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'
			|| str[i] == '+'))
		i++;
	while (str[i] && (str[i] == ' '))
		i++;
	if (str[i] && (ft_isdigit(str[i]) || str[i] == '-'
			|| str[i] == '+'))
		return (TRUE);
	return (FALSE);
}

void	get_all(char *str, char **arr, int *t)
{
	char	**tmp;
	int		n;

	n = 0;
	tmp = ft_split(str, " ");
	if (!tmp)
		my_exit(1, arr, "Error", NULL);
	while (tmp[n])
	{
		arr[*t] = ft_strdup(tmp[n]);
		if (!arr[*t])
			my_exit(1, arr, "Error", NULL);
		free(tmp[n]);
		n++;
		(*t)++;
	}
	free(tmp);
}

char	**init_2d(int ac, char **av, int *c)
{
	char	**str;
	int		i;
	int		t;

	i = 0;
	t = 0;
	av++;
	*c = arg_count(ac, av);
	str = (char **)malloc(sizeof(char *) * (*c + 1));
	if (!str)
		my_exit(1, NULL, "Error", NULL);
	while (i < ac)
	{
		if (!more_than_one(av[i]))
		{
			str[t] = ft_strdup((const char *)av[i]);
			if (!str[t++])
				my_exit(1, str, "Error", NULL);
		}
		else
			get_all(av[i], str, &t);
		i++;
	}
	str[t] = NULL;
	return (str);
}
