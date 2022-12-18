/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:23:18 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/17 10:44:00 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check1(t_list **a, t_list **b, t_allvar *allvar)
{
	while (allvar->i < allvar->btomove->bminb
		&& allvar->j < allvar->btomove->bmina)
	{
		rr(a, b);
		allvar->i++;
		allvar->j++;
	}	
	while (allvar->i < allvar->btomove->bminb)
	{
		rb(b);
		allvar->i++;
	}	
	while (allvar->j < allvar->btomove->bmina)
	{
		ra(a);
		allvar->j++;
	}
}

void	check2(t_list **a, t_list **b, t_allvar *allvar)
{
	while (allvar->i > allvar->btomove->bminb
		&& allvar->j > allvar->btomove->bmina)
	{
		rrr(a, b);
		allvar->i--;
		allvar->j--;
	}	
	while (allvar->i > allvar->btomove->bminb)
	{
		rrb(b);
		allvar->i--;
	}
	while (allvar->j > allvar->btomove->bmina)
	{
		rra(a);
		allvar->j--;
	}
}

void	check3(t_list **a, t_list **b, t_allvar *allvar)
{
	while (allvar->j > allvar->btomove->bmina)
	{
		rra(a);
		allvar->j--;
	}
	while (allvar->i < allvar->btomove->bminb)
	{
		rb(b);
		allvar->i++;
	}
}

void	check4(t_list **a, t_list **b, t_allvar *allvar)
{
	while (allvar->j < allvar->btomove->bmina)
	{
		ra(a);
		allvar->j++;
	}	
	while (allvar->i > allvar->btomove->bminb)
	{
		rrb(b);
		allvar->i--;
	}
}

void	from_b_to_a(t_list **a, t_list **b, t_allvar *allvar)
{
	while (*b)
	{
		count_best_moves(a, b, allvar);
		allvar->btomove = search_besttomove(b, allvar);
		allvar->tmpb = *b;
		allvar->i = 0;
		allvar->j = 0;
		if (allvar->btomove->bminb >= 0 && allvar->btomove->bmina >= 0)
			check1(a, b, allvar);
		else if (allvar->btomove->bminb <= 0 && allvar->btomove->bmina <= 0)
			check2(a, b, allvar);
		else if (allvar->btomove->bminb >= 0 && allvar->btomove->bmina <= 0)
			check3(a, b, allvar);
		else
			check4(a, b, allvar);
		pa(a, b);
	}
}
