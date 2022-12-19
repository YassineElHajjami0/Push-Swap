/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:16:06 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/19 14:17:38 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void    checkit(t_list **a, t_list **b, char *line, t_allvar *allvar)
{
    if (ft_strncmp(line, "sa\n", 3) == 0)
        sa(a, 1);
    if (ft_strncmp(line, "ra\n", 3) == 0)
        ra(a, 1);
    if (ft_strncmp(line, "rra\n", 3) == 0)
        rra(a, 1);
    if (ft_strncmp(line, "pa\n", 4) == 0)
        pa(a, b, 1);
    if (ft_strncmp(line, "sb\n", 4) == 0)
        sb(b, 1);
    if (ft_strncmp(line, "rb\n", 4) == 0)
        rb(b, 1);
    if (ft_strncmp(line, "rrb\n", 4) == 0)
        rrb(b, 1);
    if (ft_strncmp(line, "pb\n", 4) == 0)
        pb(a, b, 1, allvar);
    if (ft_strncmp(line, "rr\n", 4) == 0)
        rr(a, b, 1);
    if (ft_strncmp(line, "rrr\n", 4) == 0)
        rrr(a, b, 1);
    if (ft_strncmp(line, "ss\n", 4) == 0)
        ss(a, b, 1);
}

void    gettline(t_list **a, t_list **b, t_allvar *allvar)
{
    char    *line;
    line = get_next_line(0);
    while(line)
    {
        checkit(a, b, line, allvar);
        free(line);
        line = get_next_line(0);
    }
}

int main(int ac, char *av[])
{
    t_list		*a;
	t_list		*b;
	char		**str;
    t_allvar    allvar;

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
    gettline(&a, &b, &allvar);
    
    return (0);
}