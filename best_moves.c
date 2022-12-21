/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:21:26 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/21 11:22:43 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_search_bm_in_a(t_list **a, t_list *tmpb, t_allvar *allvar)
{
	allvar->frombottom = (*a)->prev;
	allvar->j = -1;
	while (1)
	{
		if (((allvar->frombottom->content > tmpb->content)
				&& (allvar->frombottom->prev->content < tmpb->content))
			|| (allvar->frombottom->prev->content > allvar->frombottom->content
				&& (tmpb->content < allvar->frombottom->content
					|| tmpb->content > allvar->frombottom->prev->content)))
			break ;
		allvar->j--;
		allvar->frombottom = allvar->frombottom->prev;
	}
	return (allvar->j);
}

void	search_bm_ina(t_list **a, t_list *tmpb, t_allvar *allvar)
{
	int	r;

	allvar->i = 0;
	allvar->fromtop = *a;
	while (1)
	{
		if (((allvar->fromtop->content > tmpb->content)
				&& (allvar->fromtop->prev->content < tmpb->content))
			|| ((allvar->fromtop->prev->content > allvar->fromtop->content)
				&& (tmpb->content < allvar->fromtop->content
					|| tmpb->content > allvar->fromtop->prev->content)))
			break ;
		allvar->i++;
		allvar->fromtop = allvar->fromtop->next;
	}
	r = help_search_bm_in_a(a, tmpb, allvar);
	if (allvar->i < r * -1)
		tmpb->bmina = allvar->i;
	else
		tmpb->bmina = r;
}

void	search_bm_inb(t_list **b, t_list *tmpb, t_allvar *allvar)
{
	allvar->i = 0;
	allvar->j = -1;
	allvar->fromtop = *b;
	allvar->frombottom = (*b)->prev;
	while (1)
	{
		if (allvar->fromtop->content == tmpb->content)
			break ;
		allvar->i++;
		allvar->fromtop = allvar->fromtop->next;
	}
	while (1)
	{
		if (allvar->frombottom->content == tmpb->content)
			break ;
		allvar->j--;
		allvar->frombottom = allvar->frombottom->prev;
	}
	if (allvar->i < allvar->j * -1)
		tmpb->bminb = allvar->i;
	else
		tmpb->bminb = allvar->j;
}

void	set_bmove(t_list *tmpb)
{
	if (tmpb->bmina >= 0 && tmpb->bminb >= 0)
	{
		if (tmpb->bmina >= tmpb->bminb)
			tmpb->bmove = tmpb->bmina;
		else
			tmpb->bmove = tmpb->bminb;
	}
	else if (tmpb->bmina <= 0 && tmpb->bminb <= 0)
	{
		if (ft_abs(tmpb->bmina) >= ft_abs(tmpb->bminb))
			tmpb->bmove = ft_abs(tmpb->bmina);
		else
			tmpb->bmove = ft_abs(tmpb->bminb);
	}
	else
	{
		tmpb->bmove = ft_abs(tmpb->bmina);
		tmpb->bmove += ft_abs(tmpb->bminb);
	}
}

void	count_best_moves(t_list **a, t_list **b, t_allvar *allvar)
{
	if (!*b)
		return ;
	allvar->tmpb = *b;
	while (1)
	{
		search_bm_ina(a, allvar->tmpb, allvar);
		search_bm_inb(b, allvar->tmpb, allvar);
		set_bmove(allvar->tmpb);
		allvar->tmpb = allvar->tmpb->next;
		if (allvar->tmpb == *b)
			break ;
	}
}
