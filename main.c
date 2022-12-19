/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:45 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/19 18:18:08 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "push_swap.h"

// void funcc(void)
// {
// 	system("leaks push_swap");
// }

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	main(int ac, char *av[])
{
	// atexit(funcc);
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
	char *o = ft_strjoin(ac - 1, av + 1, " ");
	str = ft_split(o, ' ');
	free (o);
	// return 0;
	if (!parsing(&a, str))
		return (0);
	freestr(str);
	from_a_to_b(&a, &allvar);
	set_num(&a, &allvar);
	move_to_top_of_a(&a, &b, &allvar);
	count_best_moves(&a, &b, &allvar);
	from_b_to_a(&a, &b, &allvar);
	set_the_head(&a, &allvar);
}
