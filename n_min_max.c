/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_min_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:56:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 23:08:36 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include "libft.h"

int		find_min(t_elem **a, int st_a)
{
	int					index;
	long long int		min;

	min = BAD_MIN;
	index = 0;
	while (a[st_a] != NULL)
	{
		if (a[st_a]->num < min)
		{
			min = a[st_a]->num;
			index = st_a;
		}
		++st_a;
	}
	return (index);
}

int		find_max(t_elem **a, int st_a)
{
	int					index;
	long long int		max;

	max = BAD_MAX;
	index = 0;
	while (a[st_a] != NULL)
	{
		if (a[st_a]->num > max)
		{
			max = a[st_a]->num;
			index = st_a;
		}
		++st_a;
	}
	return (index);
}
