/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/19 21:42:48 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

#include <limits.h>
#include <stdlib.h>

void	push_back(t_elem **a, t_elem **b, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		f_all("pa", a, b);
		++i;
	}
}

void	push_swap(t_stacks *s, int size)
{
	int		e1;
	int		e2;
	int		i;
	int		size_ext;

	i = 0;
	size_ext = size;
	while (i < size - 1)
	{
		e1 = s->t[i]->num;
		e2 = s->t[i + 1]->num;
		move_pair(e1, e2, s, size_ext);
		size_ext -= 2;
		i += 2;
	}
	if (size % 2 == 1)
		f_all("pb", s->a, s->b);
	push_back(s->a, s->b, size);
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;
	int			size;
	int			ret;

	size = argc - 1;
	stacks.a = new_arr_elem(size);
	stacks.b = new_arr_elem(size);
	stacks.t = new_arr_elem(size);
	ret = read_push(stacks.a, argv, argc);
	read_push(stacks.t, argv, argc);
	sort_elems(stacks.t, size);
	print_stks(stacks.a, stacks.b);
	push_swap(&stacks, size);
	print_stks(stacks.a, stacks.b);
	return (0);
}
