/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:48:09 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/20 22:46:24 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

#include <limits.h>
#include <stdlib.h>

t_elem	*new_elem(int num, int empty)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->num = num;
	new->empty = empty;
	return (new);
}

t_elem	**new_arr_elem(int size)
{
	t_elem	**new;
	int		i;

	i = 0;
	if (!(new = (t_elem**)malloc(sizeof(t_elem*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new[i] = new_elem(i, 1);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		ft_strisdig(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_isdigit(str[i]) == 0 && str[i] != '-')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		if (i >= 12)
			return (0);
		i++;
	}
	return (1);
}

int		read_push(t_elem **elems, char **argv, int argc)
{
	int				i;
	long long int	tmp;

	i = 1;
	while (i < argc)
	{
		if (ft_strisdig(argv[i]) == 0)
			return (0);
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		elems[i - 1]->num = tmp;
		elems[i - 1]->empty = 0;
		i++;
	}
	return (1);
}
