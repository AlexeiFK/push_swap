/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:52:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 22:52:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

static void		new_rc_b_min(int rc_b, long long int *rc_b_min)
{
	if (rc_b < (*rc_b_min))
		(*rc_b_min) = rc_b;
}

static void		init_max_min(int *max, int *min, t_stacks *s, int st_a)
{
	*min = find_min(s->a, st_a);
	*max = find_max(s->a, st_a);
}

long long int	n_commands_rc_minus(t_stacks *s, int st_a, int st_b)
{
	int				rc_b;
	long long int	rc_b_min;
	int				min;
	int				max;

	rc_b = 0;
	rc_b_min = BAD_MIN;
	init_max_min(&max, &min, s, st_a);
	while (s->b[st_b + rc_b] != NULL)
	{
		if (s->a[s->size - 1]->num > s->a[st_a]->num &&
				((s->b[st_b + rc_b]->num > s->a[max]->num) ||
				(s->b[st_b + rc_b]->num < s->a[min]->num)))
			new_rc_b_min(rc_b, &rc_b_min);
		else if (s->b[st_b + rc_b]->num > s->a[s->size - 1]->num)
			if (s->b[st_b + rc_b]->num < s->a[st_a]->num)
				new_rc_b_min(rc_b, &rc_b_min);
		++rc_b;
	}
	return (rc_b_min);
}

long long int	n_commands(int rc_a, t_stacks *s, int st_a, int st_b)
{
	int				rc_b;
	long long int	rc_b_min;
	int				min;
	int				max;

	rc_b = 0;
	rc_b_min = BAD_MIN;
	init_max_min(&max, &min, s, st_a);
	if (rc_a == -1)
		return (n_commands_rc_minus(s, st_a, st_b));
	while (s->b[st_b + rc_b] != NULL && s->a[st_a + rc_a + 1] != NULL)
	{
		if (s->a[st_a + rc_a]->num > s->a[st_a + rc_a + 1]->num &&
				((s->b[st_b + rc_b]->num > s->a[max]->num) ||
				(s->b[st_b + rc_b]->num < s->a[min]->num)))
			new_rc_b_min(rc_b, &rc_b_min);
		if (s->b[st_b + rc_b]->num > s->a[st_a + rc_a]->num)
			if (s->b[st_b + rc_b]->num < s->a[st_a + rc_a + 1]->num)
				new_rc_b_min(rc_b, &rc_b_min);
		++rc_b;
	}
	return (rc_b_min);
}
