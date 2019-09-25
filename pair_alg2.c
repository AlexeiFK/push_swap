/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_alg2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:55:37 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/25 19:53:23 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <limits.h>
#include <stdlib.h>

int		is_wrong(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL && a[i]->empty != 0)
		i++;
	if (a[i] == NULL || a[i + 1] == NULL)
		return (0);
	if (a[i]->num < a[i + 1]->num)
		return (1);
	else
		return (0);
}

int		get_first_id(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL && a[i]->empty != 0)
		i++;
	if (a[i] == NULL)
		return (-1);
	return (i);
}

int		find_indexes(t_elem **a, int e1, int e2, int *i2)
{
	int		ind1;
	int		ind2;
	int		i;
	int		j;

	ind1 = INT_MAX;
	ind2 = INT_MAX;
	i = 0;
	j = 0;
	while (a[i] != NULL)
	{
		if (e1 == a[i]->num && a[i]->empty != 1)
			ind1 = j;
		if (e2 == a[i]->num && a[i]->empty != 1)
			ind2 = j;
		if (a[i]->empty == 0)
			j++;
		i++;
	}
	*i2 = ind2;
	return (ind1);
}
