/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:40:52 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/18 22:03:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_pushswap.h"

void	f_sa(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL && a[i]->empty != 0)
		i++;
	if (a[i] == NULL || a[i + 1] == NULL)
		return ;
	ft_swapint(&a[i]->num, &a[i + 1]->num);
}

void	f_ss(t_elem **a, t_elem **b)
{
	f_sa(a);
	f_sa(b);
}

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

void	f_ra(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL && a[i]->empty != 0)
		i++;
	if (a[i] == NULL || a[i + 1] == NULL)
		return ;
	while (a[i + 1] != NULL)
	{
		ft_swapint(&a[i]->num, &a[i + 1]->num);
		i++;
	}
}

void	f_rra(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i + 1] != NULL)
		i++;
	while (i >= 1 && a[i - 1]->empty != 1)
	{
		ft_swapint(&a[i]->num, &a[i - 1]->num);
		i--;
	}
}
