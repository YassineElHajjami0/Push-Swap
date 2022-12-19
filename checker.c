/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:16:06 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/19 18:24:33 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	checkit(t_list **a, t_list **b, char *line, t_allvar *allvar)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, 0, allvar);
	if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
}

void	gettline(t_list **a, t_list **b, t_allvar *allvar)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		checkit(a, b, line, allvar);
		free(line);
		line = get_next_line(0);
	}
}

void	checksorting(t_list **a, t_allvar *allvar)
{
	allvar->tmpa = *a;
	allvar->tmp = (*a)->next;
	while (1)
	{
		if (allvar->tmp->content < allvar->tmpa->content)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		allvar->tmp = allvar->tmp->next;
		allvar->tmpa = allvar->tmpa->next;
		if (allvar->tmp == *a)
			break ;
	}
	write(1, "OK\n", 3);
	exit(0);
}
void funcc(void)
{
	system("leaks push_swap");

}
int	main(int ac, char *av[])
{
	atexit (funcc);
	t_list		*a;
	t_list		*b;
	char		**str;
	t_allvar	allvar;

	b = NULL;
	a = NULL;
	if (ac == 1)
	{
		write(2, "Eroor\n", 6);
		return (0);
	}
	char *o = ft_strjoin(ac - 1, av + 1, " ");
	str = ft_split(o , ' ');
	if (!parsing(&a, str))
		return (0);
	free(o);
	freestr(str);
	gettline(&a, &b, &allvar);
	checksorting(&a, &allvar);
	return (0);
}
