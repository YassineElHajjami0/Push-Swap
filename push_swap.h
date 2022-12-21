/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:11:29 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/21 11:04:46 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				count;
	int				num;
	int				bminb;
	int				bmina;
	int				bmove;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_allvar
{
	int		i;
	int		j;
	int		k;
	int		topcp;
	int		bottomcp;
	int		res;
	t_list	*tmp;
	t_list	*initialtmp;
	t_list	*tocompare;
	t_list	*rema;
	t_list	*tmpa;
	t_list	*tmpb;
	t_list	*btomove;
	t_list	*compare;
	t_list	*firsttmp;
	t_list	*lasttmp;
	t_list	*fromtop;
	t_list	*frombottom;
}				t_allvar;

t_list	*ft_lstnew(int c);
int		ft_abs(int x);
int		parsing(t_list **a, int ac, char **av);
long	ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *neww);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
void	sa(t_list **lst, int show);
void	sb(t_list **lst, int show);
void	ss(t_list **head, t_list **b, int show);
void	rra(t_list **head, int show);
void	rrb(t_list **b, int show);
void	rrr(t_list **head, t_list **b, int show);
void	ra(t_list **head, int show);
void	rb(t_list **head, int show);
void	rr(t_list **a, t_list **b, int show);
void	pb(t_list **head, t_list **b, int show, t_allvar *allvar);
int		pa(t_list **head, t_list **b, int show);
int		set_count(t_list **a, t_allvar *allvar);
void	set_num(t_list **a, t_allvar *allvar);
t_list	*closest_one_to_head(t_list **a, t_allvar *allvar);
int		fakeswaptwo(t_list **a, int watchlis, t_allvar *allvar);
int		fakeswap(t_list **a, int watchlis, t_allvar *allvar);
void	move_to_top_of_a(t_list **a, t_list **b, t_allvar *allvar);
void	from_a_to_b(t_list **a, t_allvar *allvar);
void	search_bm_ina(t_list **a, t_list *tmpb, t_allvar *allvar);
void	search_bm_inb(t_list **b, t_list *tmpb, t_allvar *allvar);
void	count_best_moves(t_list **a, t_list **b, t_allvar *allvar);
t_list	*search_besttomove(t_list **b, t_allvar *allvar);
void	check1(t_list **a, t_list **b, t_allvar *allvar);
void	check2(t_list **a, t_list **b, t_allvar *allvar);
void	check3(t_list **a, t_list **b, t_allvar *allvar);
void	check4(t_list **a, t_list **b, t_allvar *allvar);
void	from_b_to_a(t_list **a, t_list **b, t_allvar *allvar);
int		ft_strlen(t_list **a);
void	set_the_head(t_list	**a, t_allvar *allvar);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif