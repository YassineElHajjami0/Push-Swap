/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:45 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/18 14:19:51 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list		*a;
	t_list		*b;
	t_allvar	allvar;
	char		**str;

	b = NULL;
	a = NULL;
	if (ac == 1)
	{
		write(2, "Eroor\n", 6);
		return (0);
	}
	str = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
	if (!parsing(&a, str))
		return (0);
	from_a_to_b(&a, &allvar);
	set_num(&a, &allvar);
	move_to_top_of_a(&a, &b, &allvar);
	count_best_moves(&a, &b, &allvar);
	from_b_to_a(&a, &b, &allvar);
	set_the_head(&a, &allvar);
	/* //t_list *tmp = a;
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
	// printf("-------------b-------------\n"); */
	return (0);
}
