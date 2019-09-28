/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_alg2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:55:37 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 23:09:18 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
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
