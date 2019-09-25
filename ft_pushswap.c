/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:16:13 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/25 22:14:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

#include "limits.h"
#include "libft.h"

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

/*
void	special_case3(int e1, int e2, int e3, t_stacks *s)
{
	if (e1 > e2 && e2 < e3 && e3 < e1) // 3 1 2
		f_all_mult("ra", NULL, s->a, s->b);
	else if (e1 < e2 && e2 > e3 && e3 < e1) // 2 3 1 
		f_all_mult("rra", NULL, s->a, s->b);
	else if (e1 > e2 && e2 < e3 && e3 > e1) // 2 1 3
		f_all_mult("sa", NULL, s->a, s->b);
	else if (e1 < e2 && e2 > e3 && e3 > e1) // 1 3 2
		f_all_mult("rra", "sa", s->a, s->b); 
	else if (e1 < e2 && e2 < e3 && e3 > e1) // 3 2 1
		f_all_mult("sa", "rra", s->a, s->b);
	//1 2 3
}
*/
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
	push_swap_special(s, size_ext);
	push_back(s->a, s->b, size - size_ext);
}

void	push_it_back(int rc_a, int rc_b, t_stacks *s)
{
	int		ra_c;
	int		rb_c;
	int		rr_c;

	ra_c = 0;
	rb_c = 0;
	rr_c = 0;
//	ft_printf("rc_a =%d, rc_b =%d\n", rc_a, rc_b);
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

long long int	n_commands(int rc_a, t_stacks *s, int st_a, int st_b)
{
	int		rc_b;

	rc_b = 0;
	while (s->b[st_b + rc_b] != NULL && s->a[st_a + rc_a] != NULL)
	{
		ft_printf("rc_a =%d, rc_b =%d\n", rc_a, rc_b);
		if (s->b[st_b + rc_b]->num < s->a[st_a + rc_a]->num)
		{
		ft_printf("!rc_a =%d, rc_b =%d\n", rc_a, rc_b);
			return (rc_b);
		}
		++rc_b;
	}
	return (INT_MAX);
}

void	correction(t_stacks *s)
{
	int		min;
	int		i;
	int		index;

	min = INT_MAX;
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
	f_all_i(s, index, "ra");
}

void	push_one_back(t_stacks *s, int size)
{
	int		st_a;
	int		st_b;
//	int		i;
	int		rc_a;
	int		rc_a_tmp;
	int		rc_b;
	int		min;
	int		pret;

	min = size;
	st_a = get_first_id(s->a);
	st_b = get_first_id(s->b);
//	ft_printf("starta =%d, startb =%d\n", st_a, st_b);
	if (s->a[st_a]->num > s->b[st_b]->num)
	{
		f_all("pa", s->a, s->b);
		return ;
	}

	/*
	if (s->a[size - 1]->num < s->b[st_b]->num)
	{
		if (s->a[size - 1]->num < s->b[st_b]->num)
		f_all("pa", s->a, s->b);
		f_all("ra", s->a, s->b);
		return ;
	}
	*/

	rc_a_tmp = 0;
	rc_a = 0;
	rc_b = 0;
	while ((st_a + rc_a) < size) // 2)
	{
		pret = n_commands(rc_a, s, st_a, st_b);
		if (pret <= rc_a || (rc_a == 0 && pret == 1))
		{
			push_it_back(rc_a, pret, s);
			return ;
		}
		if (pret < min)
		{
			rc_a_tmp = rc_a;
			min = pret;
		}
		++rc_a;
	}
		if (pret == (INT_MAX))
		{
			f_all("pa", s->a, s->b);
			f_all("ra", s->a, s->b);
			return ;
		}
	push_it_back(rc_a_tmp, min, s);
//	ft_printf("min = %d\n", min);
	/*
	if (s->a[st_a + 1]->num > s->b[st_b]->num)
	{
		f_all("ra", s->a, s->b);
		f_all("pa", s->a, s->b);
		return ;
	}
	if (s->a[st_a + 1]->num > s->b[st_b + 1]->num)
	{
		f_all("rr", s->a, s->b);
		f_all("pa", s->a, s->b);
		return ;
	}
	*/
}

/*
 *
 * 1
 * 8
 * -12
 *  -2
 *  -5
 *  
*/
void	push_swap_new(t_stacks *s, int size)
{
//	int		e1;
//	int		e2;
	int		i;
	int		size_ext;

	i = 0;
	size_ext = size;
	while (i < size - 3)
	{
		f_all("pb", s->a, s->b);
		size_ext--;
		i++;
	}
	push_swap_special(s, size_ext);
		print_stks(s->a, s->b);
	i = 0;
	while (i < size - 3)
	{
		push_one_back(s, size);
		print_stks(s->a, s->b);
		i++;
	}
	correction(s);
		print_stks(s->a, s->b);
//	push_back(s->a, s->b, size - size_ext);
}
