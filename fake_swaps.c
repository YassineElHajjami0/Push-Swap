/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:12:08 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/21 10:38:24 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fakeswap(t_list **a, int watchlis, t_allvar *allvar)
{
	int	n;

	sa(a, 0);
	n = set_count(a, allvar);
	if (n > watchlis)
	{
		set_num(a, allvar);
		write(1, "sa\n", 3);
		return (n);
	}
	else
	{
		sa(a, 0);
		n = set_count(a, allvar);
		return (watchlis);
	}
}

int	count_a_len(t_list **a)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	while (1)
	{
		i++;
		tmp = tmp->next;
		if (tmp == *a)
			break ;
	}
	return (i);
}

void	move_to_top_of_a(t_list **a, t_list **b, t_allvar *allvar)
{
	int	i;
	int	j;

	j = count_a_len(a);
	i = set_count(a, allvar);
	while (j > i)
	{
		i = fakeswap(a, i, allvar);
		if ((*a)->num == 0)
		{
			pb(a, b, 1, allvar);
			j --;
		}
		else
			rr(a, b, 1);
	}
}

void	from_a_to_b(t_list **a, t_allvar *allvar)
{
	int	watchlis;

	watchlis = set_count(a, allvar);
	watchlis = fakeswap(a, watchlis, allvar);
}
