/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:17 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/19 15:17:40 by yel-hajj         ###   ########.fr       */
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
		write(1, "sa\n", 3);
}

void	sb(t_list **lst, int show)
{
	t_list	*tmp;
	t_list	*lhead;

	if (!lst)
	{
		write(2, "Eroor\n", 6);
		exit(0);
	}
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
		write(1, "sa\n", 3);
}

void	pb(t_list **head, t_list **b, int show, t_allvar *allvar)
{
	if (!*head)
	{
		write(2, "Eroor\n", 6);
		exit(0);
	}
	allvar->tmp = (*head)->next;
	allvar->tmp->prev = (*head)->prev;
	(*head)->prev->next = allvar->tmp;
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
	*head = allvar->tmp;
	if (show == 1)
		write(1, "pb\n", 3);
}

void	helpa(t_list **head, t_list **b, int show)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = (*b)->next;
	tmp->prev = (*b)->prev;
	(*b)->prev->next = tmp;
	(*b)->next = *head;
	(*b)->prev = (*head)->prev;
	(*head)->prev->next = *b;
	(*head)->prev = *b;
	*head = *b;
	*b = tmp;
	if (show == 1)
		write(1, "pa\n", 3);
}

int	pa(t_list **head, t_list **b, int show)
{
	t_list	*tmp;

	tmp = NULL;
	if (!*b)
	{
		write(2, "Eroor\n", 6);
		exit(0);
	}
	if ((*b)->next == *b)
	{
		(*b)->next = *head;
		(*b)->prev = (*head)->prev;
		(*head)->prev->next = *b;
		(*head)->prev = *b;
		*head = *b;
		*b = tmp;
		if (show == 1)
			write(1, "pa\n", 3);
		return (1);
	}
	else
	{
		helpa(head, b, show);
		return (2);
	}
}
