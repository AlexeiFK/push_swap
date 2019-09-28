/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_push_one_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:03:25 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 22:54:41 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include "libft.h"

static void	init_res(t_res *r)
{
	r->min = BAD_MIN;
	r->rc_a_tmp = 0;
	r->flag = 0;
}

static void	new_res(t_res *r, int rc_a)
{
	if (max_between_two(rc_a + 1, r->pret) <
			max_between_two(r->rc_a_tmp + 1, r->min))
	{
		r->rc_a_tmp = rc_a;
		r->min = r->pret;
	}
}

static void	new_res_rev(t_res *r, int rc_a, int size)
{
	if (r->pret < 0)
		r->pret = r->pret * -1;
	if (r->flag == 0 && (max_between_two(size - (rc_a + 1), r->pret) <
				max_between_two(r->rc_a_tmp + 1, r->min)))
	{
		r->flag = 1;
		r->rc_a_tmp = rc_a;
		r->min = r->pret;
	}
	else if (r->flag == 1 && (max_between_two(size - (rc_a + 1), r->pret)
				< max_between_two(size - (r->rc_a_tmp + 1), r->min)))
	{
		r->flag = 1;
		r->rc_a_tmp = rc_a;
		r->min = r->pret;
	}
}

static void	push_flag(t_res *r, t_stacks *s, int size)
{
	if (!r->flag)
		push_it_back(r->rc_a_tmp + 1, r->min, s);
	else
		push_it_back_rev(size - (r->rc_a_tmp + 1), r->min, s);
}

void		push_one_back(t_stacks *s, int size)
{
	int		st_a;
	int		st_b;
	int		rc_a;
	int		rc_b;
	t_res	r;

	st_a = get_first_id(s->a);
	st_b = get_first_id(s->b);
	rc_a = -1;
	rc_b = 0;
	init_res(&r);
	while ((rc_a) <= ((size - 1) / 2))
	{
		r.pret = n_commands(rc_a, s, st_a, st_b);
		new_res(&r, rc_a);
		++rc_a;
	}
	while ((rc_a) < (size - 1))
	{
		r.pret = n_commands_rev(rc_a, s, st_a, st_b) - 1;
		new_res_rev(&r, rc_a, size);
		++rc_a;
	}
	push_flag(&r, s, size);
}
