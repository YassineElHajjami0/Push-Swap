/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:48 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/18 14:20:56 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head)
{
	*head = (*head)->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	*b = (*b)->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **head, t_list **b)
{
	rra(head);
	rrb(b);
	write(1, "rrr\n", 4);
}

void	ra(t_list **head)
{
	*head = (*head)->next;
	write(1, "ra\n", 3);
}

void	rb(t_list **head)
{
	*head = (*head)->next;
	write(1, "rb\n", 3);
}
