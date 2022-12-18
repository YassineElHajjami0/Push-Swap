/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcounts_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:53 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/18 14:06:01 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_set_count(t_list **a, t_allvar *allvar)
{
	allvar->tmp = (*a)->next;
	allvar->initialtmp = *a;
	while (1)
	{
		if (allvar->tmp->count >= allvar->initialtmp->count)
			allvar->initialtmp = allvar->tmp;
		allvar->tmp = allvar->tmp->next;
		if (allvar->tmp == *a)
			break ;
	}
	return (allvar->initialtmp->count);
}

int	set_count(t_list **a, t_allvar *allvar)
{
	allvar->initialtmp = *a;
	while (1)
	{
		allvar->initialtmp->count = 1;
		allvar->tmp = allvar->initialtmp;
		allvar->tocompare = allvar->initialtmp->next;
		while (allvar->tmp->next != allvar->initialtmp
			&& allvar->tocompare != allvar->initialtmp)
		{
			if (allvar->tocompare->content > allvar->tmp->content)
			{
				allvar->initialtmp->count += 1;
				allvar->tmp = allvar->tocompare;
			}
			allvar->tocompare = allvar->tocompare->next;
		}
		allvar->initialtmp = allvar->initialtmp->next;
		if (allvar->initialtmp == *a)
			break ;
	}
	return (help_set_count(a, allvar));
}

void	set_num(t_list **a, t_allvar *allvar)
{
	allvar->initialtmp = *a;
	allvar->tmp = (*a)->next;
	while (allvar->initialtmp->next != *a && allvar->tmp != *a)
	{
		if (allvar->tmp->count >= allvar->initialtmp->count)
			allvar->initialtmp = allvar->tmp;
		allvar->tmp = allvar->tmp->next;
	}
	allvar->tmp = allvar->initialtmp;
	allvar->tocompare = allvar->initialtmp->next;
	while (allvar->tocompare != allvar->initialtmp)
	{
		if (allvar->tocompare->content > allvar->tmp->content)
		{
			allvar->tmp->num = 1;
			allvar->tocompare->num = 1;
			allvar->tmp = allvar->tocompare;
		}
		else
			allvar->tocompare->num = 0;
		allvar->tocompare = allvar->tocompare->next;
	}
}

t_list	*closest_one_to_head(t_list **a, t_allvar *allvar)
{
	allvar->firsttmp = *a;
	allvar->lasttmp = (*a)->prev;
	allvar->topcp = 0;
	allvar->bottomcp = -1;
	while (1)
	{
		if (allvar->firsttmp->num == 0)
			break ;
		allvar->topcp++;
		allvar->firsttmp = allvar->firsttmp->next;
		if (allvar->firsttmp == *a)
			return (NULL);
	}
	while (1)
	{
		if (allvar->lasttmp->num == 0)
			break ;
		allvar->bottomcp--;
		allvar->lasttmp = allvar->lasttmp->prev;
	}
	if (allvar->topcp < allvar->bottomcp * -1)
		return (allvar->res = allvar->topcp, allvar->firsttmp);
	else
		return (allvar->res = allvar->bottomcp, allvar->firsttmp);
}
