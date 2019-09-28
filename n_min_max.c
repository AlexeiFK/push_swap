/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_min_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:56:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 20:57:51 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include "limits.h"
#include "libft.h"

int		find_min(t_elem **a, int st_a)
{
	int		index;
	int		min;

	min = INT_MAX;
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
	int		index;
	int		max;

	max = INT_MIN;
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
