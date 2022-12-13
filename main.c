/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:45 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/13 10:01:25 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "push_swap.h"

t_list	*ft_lstnew(int c)
{
	t_list	*n;

	n = (t_list *)malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->content = c;
	n->next = NULL;
	n->prev = NULL;
	n->count = 0;
	n->num = 0;
	n->bmove = 0;
	return (n);
}

int	ft_atoi(const char *str)
{
	int		i;
	size_t	res;
	int		nakis;

	i = 0;
	res = 0;
	nakis = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nakis *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		if (res > 9223372036854775807 && nakis > 0)
			return (-1);
		if (res > 0 && res - 1 > 9223372036854775807 && nakis < 0)
			return (0);
		i++;
	}
	return ((int)res * nakis);
}

void	ft_lstadd_back(t_list **lst, t_list *neww)
{
	t_list	*t;
	if (lst && neww)
	{
		if (!*lst)
		{
			*lst = neww;
			neww->next = *lst;
			neww->prev = *lst;
		}
		else
		{
			t = *lst;
			while (t->next != *lst)
				t = t->next;
			t->next = neww;
			neww->next = *lst;
			neww->prev = t;
			(*lst)->prev = neww;
		}
	}

}

void	sa(t_list **lst, int show)
{
	t_list *tmp;
	t_list *lhead;

	lhead = (*lst);
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next->prev = *lst;
	tmp->next =	*lst;
	tmp->prev =	(*lst)->prev;
	(*lst)->prev = tmp;
	while(lhead->next != *lst)
		lhead = lhead->next;
	lhead->next = tmp;
	*lst = tmp;
	if(show == 1)
		printf("sa\n");
}

void	sb(t_list **lst)
{
	t_list *tmp;
	t_list *lhead;

	lhead = (*lst);
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next->prev = *lst;
	tmp->next =	*lst;
	tmp->prev =	(*lst)->prev;
	(*lst)->prev = tmp;
	while(lhead->next != *lst)
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

void	rr(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	printf("rr\n");
}

void	pb(t_list **head,t_list **b)
{
	if(!*head)
		return ;
	t_list *tmp;
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

int	pa(t_list **head,t_list **b)
{
	t_list *tmp = NULL;

	if(!*b || !*head)
		return 0;
	if((*b)->next == *b)
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
		return(2);
	}
}

//--------from a to b

int	separate_a_b(t_list **a, t_list **b)
{
	t_list *tmp;
	t_list *initialtmp;
	t_list *tocompare;

	initialtmp = *a;
	//set the count of each node
	while (1)
	{
		initialtmp->count = 1;
		tmp = initialtmp;
		tocompare = initialtmp->next;
		while (tmp->next != initialtmp && tocompare != initialtmp)
		{
			if (tocompare->content > tmp->content)
			{
				initialtmp->count += 1;
				tmp = tocompare;
			}
			tocompare = tocompare->next;
		}
		initialtmp = initialtmp->next;
		if(initialtmp == *a)
			break;
	}
	tmp = (*a)->next;
	initialtmp = *a;
	while(1)
	{
		if(tmp->count >= initialtmp->count)
			initialtmp = tmp;
		tmp = tmp->next;
		if(tmp == *a)
			break ;
	}
	return initialtmp->count;
}

void	set_num(t_list **a, t_list **b)
{
	t_list *tmp;
	t_list *initialtmp;
	t_list *tocompare;

	initialtmp = *a;
	tmp = initialtmp;
	tocompare = initialtmp->next;
	while (tocompare != initialtmp)
	{
		if (tocompare->content > tmp->content)
		{
			tmp->num = 1;
			tocompare->num = 1;
			tmp = tocompare;
		}
		tocompare = tocompare->next;
	}
}

t_list		*closest_one_to_head(t_list **a, t_allvar *allvar) 
{
	t_list *firsttmp;
	t_list *lasttmp;

	firsttmp = *a;
	lasttmp = (*a)->prev;
	allvar->topcp = 0;
	allvar->bottomcp = -1;
	while(1)
	{
		if(firsttmp->num == 0)
			break ;
		allvar->topcp++;
		firsttmp = firsttmp->next;
		if(firsttmp == *a)
			return (NULL);
	}
	while(1)
	{
		if(lasttmp->num == 0)
			break ;
		allvar->bottomcp--;
		lasttmp= lasttmp->prev;
	}
	if (allvar->topcp < allvar->bottomcp * -1)
	{
			allvar->res = allvar->topcp;
			return (firsttmp);
	}
	else
	{
		allvar->res = allvar->bottomcp;
		return	(firsttmp);
	}
}

int		fakeswap(t_list **a,t_list **b, int watchlis)
{
	int n;
	
	sa(a, 0);
	n = separate_a_b(a, b);
	if(n > watchlis)
	{
		(*a)->next->num = 1;
		printf("sa\n");
		return (n);
	}
	else
	{
		sa(a, 0);
		n = separate_a_b(a, b);
		return (watchlis);
	}
}

void	move_to_top_of_a(t_list **a, t_list **b, t_allvar *allvar)
{
	t_list *aa;
	int	i;
	
	i = aa->count;
	aa = *a;
	while(1)
	{
		i = fakeswap(a, b, i);
		if (!closest_one_to_head(a, allvar))
			break ;
		if(allvar->res == 0 && (*a)->num == 0)
		{
			pb(a, b);
			continue ;
		}
		if(allvar->res > 0)
			ra(a);
		else
			rra(a);
	}
	*a = aa;
}

void	from_a_to_b(t_list **a,t_list **b,t_allvar *allvar)
{
	t_list *initialtmp;
	t_list	*tmp;
	int	watchlis;

	watchlis = separate_a_b(a, b);
	watchlis = fakeswap(a, b, watchlis);
	initialtmp = *a;
	tmp = (*a)->next;
	while(initialtmp->next != *a && tmp != *a)
	{
		if(tmp->count >= initialtmp->count)
			initialtmp = tmp;
		tmp = tmp->next;
	}*a = initialtmp;
}

//--------from b to a

int main(int ac, char *av[])
{
    t_list *a;
	t_list *b;
	t_allvar allvar;
	int i = 1;

	//printf("length %d\n", ac - 1);
	b = NULL;
	a = NULL;
	while(av[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	// ft_lstadd_back(&a, ft_lstnew(0));
	// ft_lstadd_back(&a, ft_lstnew(1));
	// ft_lstadd_back(&a, ft_lstnew(7));
	// ft_lstadd_back(&a, ft_lstnew(5));
	// ft_lstadd_back(&a, ft_lstnew(10));
	// ft_lstadd_back(&a, ft_lstnew(2));
	// ft_lstadd_back(&a, ft_lstnew(11));
	// ft_lstadd_back(&a, ft_lstnew(12));
	from_a_to_b(&a, &b, &allvar);
	set_num(&a, &b);
	move_to_top_of_a(&a, &b, &allvar);
	count_best_moves(&a, &b, &allvar);
	//put_in_b(&a, &b);
	t_list *tmp = a;
	printf("-------------a-------------\n");
	while(a && tmp->next != a)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
	printf("-------------a-------------\n");
	printf("-------------b-------------\n");
	tmp = b;
	while(b && tmp->next != b)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
	printf("-------------b-------------\n");
    return (0);
}