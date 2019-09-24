/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:49:42 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:06:15 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_pushswap.h"

void	f_pb(t_elem **a, t_elem **b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (a[i] != NULL && a[i]->empty != 0)
		i++;
	if (a[i] == NULL)
		return ;
	while (b[j] != NULL && b[j]->empty != 0)
		j++;
	j--;
	ft_swapint(&a[i]->num, &b[j]->num);
	ft_swapint(&a[i]->empty, &b[j]->empty);
}

void	f_pa(t_elem **a, t_elem **b)
{
	f_pb(b, a);
}
