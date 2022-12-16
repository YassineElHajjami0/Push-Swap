/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:45 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/16 16:28:21 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "push_swap.h"

int main(int ac, char *av[])
{
	int			i;
    t_list		*a;
	t_list		*b;
	t_allvar	allvar;
	
	i = 1;
	//printf("length %d\n", ac - 1);
	b = NULL;
	a = NULL;
	while(av[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	from_a_to_b(&a, &allvar);
	set_num(&a, &allvar);
	move_to_top_of_a(&a, &b, &allvar);
	count_best_moves(&a, &b, &allvar);
	from_b_to_a(&a, &b, &allvar);
	set_the_head(&a, &allvar);
	ac = 1;
	//put_in_b(&a, &b);
	// t_list *tmp = a;
	// printf("-------------a-------------\n");
	// while(a && tmp->next != a)
	// {
	// 	printf("%d num= %d  count = %d\n", tmp->content, tmp->num, tmp->count);
	// 	tmp = tmp->next;
	// }
	// printf("%d num= %d  count = %d\n", tmp->content, tmp->num, tmp->count);
	// printf("-------------a-------------\n");
	// printf("-------------b-------------\n");
	// tmp = b;
	// while(b && tmp->next != b)
	// {
	// 	printf("b->content : %d, b->bmove: %d, bmina:%d  ,  bminb:%d\n", tmp->content, tmp->bmove, tmp->bmina, tmp->bminb);
	// 	tmp = tmp->next;
	// }
	// printf("b->content : %d, b->bmove: %d, bmina:%d  ,  bminb:%d\n", tmp->content, tmp->bmove, tmp->bmina, tmp->bminb);
	// printf("-------------b-------------\n");
    return (0);
}

