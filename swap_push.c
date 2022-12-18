/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:17 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/17 11:11:06 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst, int show)
{
	t_list	*tmp;
	t_list	*lhead;

	lhead = (*lst);
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next->prev = *lst;
	tmp->next = *lst;
	tmp->prev = (*lst)->prev;
	(*lst)->prev = tmp;
	while (lhead->next != *lst)
		lhead = lhead->next;
	lhead->next = tmp;
	*lst = tmp;
	if (show == 1)
		printf("sa\n");
}

void	sb(t_list **lst)
{
	t_list	*tmp;
	t_list	*lhead;

	lhead = (*lst);
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next->prev = *lst;
	tmp->next = *lst;
	tmp->prev = (*lst)->prev;
	(*lst)->prev = tmp;
	while (lhead->next != *lst)
		lhead = lhead->next;
	lhead->next = tmp;
	*lst = tmp;
	printf("sb\n");
}

void	ss(t_list **head)
{
	sa(head, 1);
	sb(head);
	printf("ss\n");
}

void	pb(t_list **head, t_list **b)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = (*head)->next;
	tmp->prev = (*head)->prev;
	(*head)->prev->next = tmp;
	if (!*b)
	{
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else
	{
		(*head)->next = *b;
		(*head)->prev = (*b)->prev;
		(*b)->prev->next = *head;
		(*b)->prev = *head;
	}
	*b = *head;
	*head = tmp;
	printf("pb\n");
}

int	pa(t_list **head, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!*b || !*head)
		return (0);
	if ((*b)->next == *b)
	{
		(*b)->next = *head;
		(*b)->prev = (*head)->prev;
		(*head)->prev->next = *b;
		(*head)->prev = *b;
		*head = *b;
		*b = tmp;
		printf("pa\n");
		return (1);
	}
	else
	{
		tmp = (*b)->next;
		tmp->prev = (*b)->prev;
		(*b)->prev->next = tmp;
		(*b)->next = *head;
		(*b)->prev = (*head)->prev;
		(*head)->prev->next = *b;
		(*head)->prev = *b;
		*head = *b;
		*b = tmp;
		printf("pa\n");
		return (2);
	}
}
