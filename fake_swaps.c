/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:12:08 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/16 16:17:19 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fakeswaptwo(t_list **a, int watchlis, t_allvar *allvar)
{
	int n;
	
	sa(a, 0);
	n = set_count(a, allvar);
	if(n > watchlis)
	{
		set_num(a, allvar); 
		printf("sa\n");
		return (n);
	}
	else
	{
		sa(a, 0);
		n = set_count(a, allvar);
		return (watchlis);
	}
}

int		fakeswap(t_list **a, int watchlis, t_allvar *allvar)
{
	int n;
	
	sa(a, 0);
	n = set_count(a, allvar);
	if(n > watchlis)
	{
		(*a)->next->num = 1;
		printf("sa\n");
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
	
	i = 0;
	while(1)
	{
		i = fakeswaptwo(a, i, allvar);
		if (!closest_one_to_head(a, allvar))
			break ;
		if(allvar->res == 0 && (*a)->num == 0)
		{
			pb(a, b);
			continue ;
		}
		if(allvar->res > 0)
			ra(a);
		else
			rra(a);
	}
}

void	from_a_to_b(t_list **a, t_allvar *allvar)
{
	int	watchlis;

	watchlis = set_count(a, allvar);
	watchlis = fakeswap(a, watchlis, allvar);
}