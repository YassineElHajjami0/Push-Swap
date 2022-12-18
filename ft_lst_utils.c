/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:04:53 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/18 14:19:02 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rr(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}
