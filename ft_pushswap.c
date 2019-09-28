/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:16:13 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 22:51:05 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include "libft.h"

void			push_it_back(int rc_a, int rc_b, t_stacks *s)
{
	int		ra_c;
	int		rb_c;
	int		rr_c;

	ra_c = 0;
	rb_c = 0;
	rr_c = 0;
	if (rc_a < rc_b)
	{
		rr_c = rc_a;
		rb_c = rc_b - rc_a;
	}
	else
	{
		rr_c = rc_b;
		ra_c = rc_a - rc_b;
	}
	f_all_i(s, rr_c, "rr");
	f_all_i(s, rb_c, "rb");
	f_all_i(s, ra_c, "ra");
	f_all_i(s, 1, "pa");
}

void			push_it_back_rev(int rc_a, int rc_b, t_stacks *s)
{
	int		ra_c;
	int		rb_c;
	int		rr_c;

	ra_c = 0;
	rb_c = 0;
	rr_c = 0;
	if (rc_a < rc_b)
	{
		rr_c = rc_a;
		rb_c = rc_b - rc_a;
	}
	else
	{
		rr_c = rc_b;
		ra_c = rc_a - rc_b;
	}
	f_all_i(s, rr_c, "rrr");
	f_all_i(s, rb_c, "rrb");
	f_all_i(s, ra_c, "rra");
	f_all_i(s, 1, "pa");
}

void			correction(t_stacks *s)
{
	long long int		min;
	int					i;
	int					index;

	min = BAD_MIN;
	index = 0;
	i = 0;
	while (s->a[i] != NULL)
	{
		if (s->a[i]->num < min)
		{
			min = s->a[i]->num;
			index = i;
		}
		i++;
	}
	if (index < (s->size / 2))
		f_all_i(s, index, "ra");
	else
		f_all_i(s, s->size - index, "rra");
}

long long int	max_between_two(long long int n1, long long int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

void			push_swap_new(t_stacks *s, int size)
{
	int		i;
	int		size_ext;
	int		cut;

	i = 0;
	cut = size - 3;
	size_ext = size;
	s->size = size;
	while (i < size - 3)
	{
		f_all("pb", s->a, s->b);
		size_ext--;
		i++;
	}
	push_swap_special(s, size_ext);
	i = 0;
	size_ext = 3;
	while (i < size - 3)
	{
		push_one_back(s, size_ext);
		i++;
		size_ext++;
	}
	correction(s);
}
