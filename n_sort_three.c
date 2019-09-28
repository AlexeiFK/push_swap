/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_sort_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:06:05 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 21:06:32 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include "libft.h"

void	special_case3(int e1, int e2, int e3, t_stacks *s)
{
	if (e1 < e2 && e2 > e3 && e3 > e1)
		f_all_mult("rra", "sa", s->a, s->b);
	else if (e1 > e2 && e2 < e3 && e3 > e1)
		f_all_mult("sa", NULL, s->a, s->b);
	else if (e1 < e2 && e2 > e3 && e3 < e1)
		f_all_mult("rra", NULL, s->a, s->b);
	else if (e1 > e2 && e2 < e3 && e3 < e1)
		f_all_mult("ra", NULL, s->a, s->b);
	else if (e1 > e2 && e2 > e3 && e3 < e1)
		f_all_mult("sa", "rra", s->a, s->b);
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
