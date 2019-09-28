/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_commands_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:51:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 22:53:16 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

static void		new_rc_b_max(int rc_b, long long int *rc_b_max)
{
	if (rc_b > (*rc_b_max))
		(*rc_b_max) = rc_b;
}

static void		init_max_min(int *max, int *min, t_stacks *s, int st_a)
{
	*min = find_min(s->a, st_a);
	*max = find_max(s->a, st_a);
}

long long int	n_commands_rev(int rc_a, t_stacks *s, int st_a, int st_b)
{
	int					rc_b;
	long long int		rc_b_max;
	int					st_b_tmp;
	int					min;
	int					max;

	rc_b = 0;
	rc_b_max = BAD_MAX;
	st_b_tmp = st_b;
	st_b = s->size - 1;
	init_max_min(&max, &min, s, st_a);
	while ((st_b_tmp <= rc_b + st_b) && s->a[st_a + rc_a + 1] != NULL)
	{
		if (s->a[st_a + rc_a]->num > s->a[st_a + rc_a + 1]->num &&
				((s->b[st_b + rc_b]->num > s->a[max]->num) ||
				(s->b[st_b + rc_b]->num < s->a[min]->num)))
			new_rc_b_max(rc_b, &rc_b_max);
		if (s->b[st_b + rc_b]->num > s->a[st_a + rc_a]->num)
		{
			if (s->b[st_b + rc_b]->num < s->a[st_a + rc_a + 1]->num)
				new_rc_b_max(rc_b, &rc_b_max);
		}
		--rc_b;
	}
	return (rc_b_max);
}
