/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/19 23:43:18 by rjeor-mo         ###   ########.fr       */
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

void	special_case3(int e1, int e2, int e3, t_stacks *s)
{
	/*
	if (e1 < e2 && e2 < e3 && e3 > e1)
	{
		ft_printf("123\n");
	}
	else */if (e1 < e2 && e2 > e3 && e3 > e1)
	{
//		ft_printf("132\n");
		f_all_mult("rra", "sa", s->a, s->b);
	}
	else if (e1 > e2 && e2 < e3 && e3 > e1)
	{
//		ft_printf("213\n");
		f_all_mult("sa", NULL, s->a, s->b);
	}
	else if (e1 < e2 && e2 > e3 && e3 < e1)
	{
//		ft_printf("231\n");
		f_all_mult("rra", NULL, s->a, s->b);
	}
	else if (e1 > e2 && e2 < e3 && e3 < e1)
	{
//		ft_printf("312\n");
		f_all_mult("ra", NULL, s->a, s->b);
	}
	else if (e1 > e2 && e2 > e3 && e3 < e1)
	{
//		ft_printf("321\n");
		f_all_mult("sa", "rra", s->a, s->b);
	}
}

void	sort3(t_stacks *s)
{	
	int		i;
	int		e1;
	int		e2;
	int		e3;

	i = 0;
	while (s->a[i] != NULL && s->a[i]->empty != 0)
		i++;
	if (s->a[i] == NULL || s->a[i + 1] == NULL
			|| s->a[i + 2] == NULL)
		return ;
	e1 = s->a[i]->num;
	e2 = s->a[i + 1]->num;
	e3 = s->a[i + 2]->num;
	special_case3(e1, e2, e3, s);
}

void	push_swap_special(t_stacks *s, int size)
{
	if (size == 2)
	{
		if (is_wrong(s->a) == 0)
			f_all("sa", s->a, s->b);
	}
	else if (size == 3)
		sort3(s);
}

void	push_swap(t_stacks *s, int size)
{
	int		e1;
	int		e2;
	int		i;
	int		size_ext;

	i = 0;
	size_ext = size;
	while (i < size - 3)
	{
		e1 = s->t[i]->num;
		e2 = s->t[i + 1]->num;
		move_pair(e1, e2, s, size_ext);
		size_ext -= 2;
		i += 2;
	}
//	print_stks(s->a, s->b);
//	ft_printf("size =%d\n", size_ext);
	push_swap_special(s, size_ext);
//	print_stks(s->a, s->b);
	push_back(s->a, s->b, size - size_ext);
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
	//print_stks(stacks.a, stacks.b);
	push_swap(&stacks, size);
	//print_stks(stacks.a, stacks.b);
	return (0);
}
