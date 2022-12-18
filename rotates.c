/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:48 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/17 11:03:42 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head)
{
	*head = (*head)->prev;
	printf("rra\n");
}

void	rrb(t_list **b)
{
	*b = (*b)->prev;
	printf("rrb\n");
}

void	rrr(t_list **head, t_list **b)
{
	rra(head);
	rrb(b);
	printf("rrr\n");
}

void	ra(t_list **head)
{
	*head = (*head)->next;
	printf("ra\n");
}

void	rb(t_list **head)
{
	*head = (*head)->next;
	printf("rb\n");
}
