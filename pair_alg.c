/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:53:32 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:09:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		find_shortest_rot(int size, int ind1, int ind2, int *l2)
{
	int		len1;
	int		len2;

	if ((size - ind1) > ind1)
		len1 = ind1;
	else
		len1 = size - ind1;
	if ((size - ind2) > ind2)
		len2 = ind2;
	else
		len2 = size - ind2;
	*l2 = len2;
	return (len1);
}

int		rotate_to_num1(t_elem **a, int len1, int size, int ind1)
{
	if ((size - ind1) > ind1)
		f_ra_i(a, len1);
	else
		f_rra_i(a, len1);
	return (1);
}

int		rotate_to_num2(t_elem **a, int len2, int size, int ind2)
{
	if ((size - ind2) > ind2)
		f_ra_i(a, len2);
	else
		f_rra_i(a, len2);
	return (2);
}

void	push_b_and_swap(t_stacks *s)
{
	f_all("pb", s->a, s->b);
	if (is_wrong(s->b) == 1)
		f_all("sb", s->a, s->b);
}

void	move_pair(int e1, int e2, t_stacks *s, int size_ext)
{
	int		ind1;
	int		ind2;
	int		len1;
	int		len2;
	int		flag;

	ind1 = find_indexes(s->a, e1, e2, &ind2);
	len1 = find_shortest_rot(size_ext, ind1, ind2, &len2);
	if (len1 < len2)
		flag = rotate_to_num1(s->a, len1, size_ext, ind1);
	else
		flag = rotate_to_num2(s->a, len2, size_ext, ind2);
	f_all("pb", s->a, s->b);
	ind1 = find_indexes(s->a, e1, e2, &ind2);
	if (flag == 1)
	{
		len1 = find_shortest_rot(size_ext - 1, ind1, ind2, &len2);
		rotate_to_num2(s->a, len2, size_ext - 1, ind2);
	}
	else if (flag == 2)
	{
		len1 = find_shortest_rot(size_ext - 1, ind1, ind2, &len2);
		rotate_to_num1(s->a, len1, size_ext - 1, ind1);
	}
	push_b_and_swap(s);
}
