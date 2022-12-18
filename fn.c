/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:26:22 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/17 10:39:22 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*search_besttomove(t_list **b, t_allvar *allvar)
{
	t_list	*bb;

	bb = *b;
	allvar->compare = (*b)->next;
	while (1)
	{
		if (allvar->compare->bmove < bb->bmove)
			bb = allvar->compare;
		allvar->compare = allvar->compare->next;
		if (allvar->compare == *b)
			break ;
	}
	return (bb);
}

int	ft_strlen(t_list **a)
{
	t_list	*t;
	int		i;

	i = 1;
	t = (*a)->next;
	while (*a != t)
	{
		t = t->next;
		i++;
	}
	return (i);
}

void	set_the_head(t_list	**a, t_allvar *allvar)
{
	allvar->tmpa = *a;
	allvar->i = 0;
	allvar->compare = allvar->tmpa->next;
	while (allvar->compare != *a)
	{
		if (allvar->compare->content < allvar->tmpa->content)
		{
			allvar->tmpa = allvar->compare;
			allvar->k = allvar->i;
		}
		allvar->i++;
		allvar->compare = allvar->compare->next;
	}
	allvar->j = ft_strlen(a);
	if (allvar->k < allvar->j / 2)
	{
		while (*a != allvar->tmpa)
			ra(a);
	}
	else
	{
		while (*a != allvar->tmpa)
			rra(a);
	}
}
