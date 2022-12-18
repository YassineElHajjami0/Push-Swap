/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:37:41 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/18 12:49:22 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*check(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		res;

	s = NULL;
	i = 0;
	res = 0;
	if (size == 0)
	{
		s = (char *)malloc(sizeof(char));
		if (!s)
			return (NULL);
		return (s);
	}
	while (i < size)
		res = res + len(strs[i++]) + len(sep);
	s = (char *)malloc((res - len(sep) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		l;
	char	*s;

	s = NULL;
	i = 0;
	j = 0;
	l = 0;
	s = check(size, strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			s[l++] = strs[i][j++];
		j = 0;
		if (i == size - 1)
			break ;
		while (sep[j])
			s[l++] = sep[j++];
		i++;
	}
	s[l] = '\0';
	return (s);
}
