/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:11:29 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/13 15:03:53 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int			content;
	int			count;
	int			num;
	int			bminb;
	int			bmina;
	int			bmove;
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
	t_list	*rema;
	t_list	*tmpa;
	t_list	*tmpb;
	t_list	*btomove;
	t_list	*compare;
	t_list	*fromtop;
	t_list	*frombottom;
}				t_allvar;



#endif
