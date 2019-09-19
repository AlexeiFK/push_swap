/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:17:37 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/19 20:55:22 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_pushswap.h"

void	ft_swapint(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	f_rrr(t_elem **a, t_elem **b)
{
	f_rra(a);
	f_rra(b);
}

void	f_rr(t_elem **a, t_elem **b)
{
	f_ra(a);
	f_ra(b);
}

void	f_rra_i(t_elem **a, int i)
{
	while (i > 0)
	{
		f_all("rra", a, NULL);
		--i;
	}
}

void	f_ra_i(t_elem **a, int i)
{
	while (i > 0)
	{
		f_all("ra", a, NULL);
		--i;
	}
}
