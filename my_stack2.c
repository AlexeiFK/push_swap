/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:42:32 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 17:12:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

#include <limits.h>
#include <stdlib.h>

int		is_sorted_stacks(t_stacks *s, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (s->a[i]->empty == 1)
			return (0);
		if (s->a[i]->num != s->t[i]->num)
			return (0);
		i++;
	}
	return (1);
}

int		is_not_dupl(t_elem **t)
{
	int		i;

	i = 0;
	while (t[i + 1] != NULL)
	{
		if (t[i]->num == t[i + 1]->num)
			return (0);
		i++;
	}
	return (1);
}

int		read_argv(t_stacks *s, char **argv,
		int argc, int *new_size)
{
	int		size;

	size = argc - 1;
	*new_size = size;
	s->a = new_arr_elem(size);
	s->b = new_arr_elem(size);
	s->t = new_arr_elem(size);
	if (read_push(s->a, argv, argc) == 0)
		return (free_stacks_ret_zero(s));
	if (read_push(s->t, argv, argc) == 0)
		return (free_stacks_ret_zero(s));
	sort_elems(s->t, size);
	if (is_not_dupl(s->t) == 0)
		return (free_stacks_ret_zero(s));
	return (1);
}

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
