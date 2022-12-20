/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:48 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/20 16:55:17 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head, int show)
{
	if (!*head)
		return ;
	*head = (*head)->prev;
	if (show == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int show)
{
	if (!*b)
		return ;
	*b = (*b)->prev;
	if (show == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **head, t_list **b, int show)
{
	rra(head, 0);
	rrb(b, 0);
	if (show == 1)
		write(1, "rrr\n", 4);
}

void	ra(t_list **head, int show)
{
	if (!*head)
		return ;
	*head = (*head)->next;
	if (show == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **head, int show)
{
	if (!*head)
		return ;
	*head = (*head)->next;
	if (show == 1)
		write(1, "rb\n", 3);
}
