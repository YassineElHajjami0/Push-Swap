/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:26:22 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/19 12:34:05 by yel-hajj         ###   ########.fr       */
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
			ra(a, 1);
	}
	else
	{
		while (*a != allvar->tmpa)
			rra(a, 1);
	}
}

void	ss(t_list **head, int show)
{
	sa(head, 0);
	sb(head, 0);
	if(show == 1)
		write(1, "ss\n", 3);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	if (!n)
		return (0);
	i = 0;
	r = 0;
	while ((s1[i] || s2[i]) && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (r = (unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}