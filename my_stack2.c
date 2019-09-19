/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:42:32 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/19 21:52:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

#include <limits.h>
#include <stdlib.h>

int		sort_elems(t_elem **a, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (a[j]->num > a[j + 1]->num)
				ft_swapint(&a[j]->num, &a[j + 1]->num);
			j++;
		}
		i++;
	}
	while (i > (size / 2))
	{
		i--;
	}
	return (a[i]->num);
}

void	print_stks(t_elem **a, t_elem **b)
{
	int		i;

	ft_printf("\n");
	i = 0;
	while (a[i] != NULL)
	{
		ft_printf("[%d]", i);
		if (a[i]->empty == 0)
			ft_printf("%12d", a[i]->num);
		else
			ft_printf("%12s", "-");
		ft_printf(" ");
		if (b[i]->empty == 0)
			ft_printf("%12d", b[i]->num);
		else
			ft_printf("%12s", "-");
		ft_printf("\n");
		i++;
	}
	ft_printf("--------------\n");
}
