/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:12:08 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/19 13:08:39 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fakeswaptwo(t_list **a, int watchlis, t_allvar *allvar)
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

int	fakeswap(t_list **a, int watchlis, t_allvar *allvar)
{
	int	n;

	sa(a, 0);
	n = set_count(a, allvar);
	if (n > watchlis)
	{
		(*a)->next->num = 1;
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

void	move_to_top_of_a(t_list **a, t_list **b, t_allvar *allvar)
{
	int	i;

	i = set_count(a, allvar);
	while (1)
	{
		i = fakeswaptwo(a, i, allvar);
		if (!closest_one_to_head(a, allvar))
			break ;
		if (allvar->res == 0 && (*a)->num == 0)
		{
			pb(a, b, 1, allvar);
			continue ;
		}
		if (allvar->res > 0)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	from_a_to_b(t_list **a, t_allvar *allvar)
{
	int	watchlis;

	watchlis = set_count(a, allvar);
	watchlis = fakeswap(a, watchlis, allvar);
}
