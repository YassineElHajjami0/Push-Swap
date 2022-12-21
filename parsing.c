/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:45:51 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/21 11:04:33 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_allint(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			if (str[i][j] < 48 || str[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_overint(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_dupint(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	parsing(t_list **a, int ac, char **av)
{
	int		i;
	char	**str;
	char	*o;

	o = ft_strjoin(ac - 1, av + 1, " ");
	str = ft_split(o, ' ');
	i = 0;
	free(o);
	if (!ft_allint(str) || !ft_overint(str) || !ft_dupint(str))
	{
		write(2, "Error\n", 6);
		freestr(str);
		return (0);
	}
	while (str[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	freestr(str);
	return (1);
}
