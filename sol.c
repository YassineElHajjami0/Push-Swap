int count_a_len(t_list **a)
{
	int i = 0;
	t_list *tmp;
	tmp = *a;
	while(1)
	{
		i++;
		tmp = tmp->next;
		if(tmp == *a)
			break;
	}
	return (i);
}

void	move_to_top_of_a(t_list **a, t_list **b, t_allvar *allvar)
{
	int	i;
	int	z;
	int	j;

	z = 0;
	j = count_a_len(a);
	printf("j = %d\n", j);
	i = set_count(a, allvar);
	while (1)
	{
		i = fakeswap(a, i, allvar);
		// if (!closest_one_to_head(a, allvar))
		// 	break ;
		// if (allvar->res == 0 && (*a)->num == 0)
		if(z == j)
			break ;
		if ((*a)->num == 0)
		{
			pb(a, b, 1, allvar);
			continue ;
		}
		else
			rra(a, 1);
		z++;
		// if (allvar->res > 0)
		// 	ra(a, 1);
		// else
		// 	rra(a, 1);
	}
}