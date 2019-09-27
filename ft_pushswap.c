/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:16:13 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/27 22:49:50 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

#include "limits.h"
#include "libft.h"

int		find_min(t_elem **a, int st_a)
{
	int		index;
	int		min;

	min = INT_MAX;
	index = 0;
	while (a[st_a] != NULL)
	{
		if (a[st_a]->num < min)
		{
			min = a[st_a]->num;
			index = st_a;
		}
		++st_a;
	}
	return (index);
}

int		find_max(t_elem **a, int st_a)
{
	int		index;
	int		max;

	max = INT_MIN;
	index = 0;
	while (a[st_a] != NULL)
	{
		if (a[st_a]->num > max)
		{
			max = a[st_a]->num;
			index = st_a;
		}
		++st_a;
	}
	return (index);
}

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

void	push_it_back_rev(int rc_a, int rc_b, t_stacks *s)
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
	f_all_i(s, rr_c, "rrr");
	f_all_i(s, rb_c, "rrb");
	f_all_i(s, ra_c, "rra");
	f_all_i(s, 1, "pa");
}
//max case
//min case
//reverse rotate add

long long int	n_commands_rev(int rc_a, t_stacks *s, int st_a, int st_b)
{
	int		rc_b;
	long long int		rc_b_max;
	int		st_b_tmp;
	int		min;
	int		max;

	rc_b = 0;
	rc_b_max = LLONG_MIN + 2;
	st_b_tmp = st_b;
	st_b = s->size - 1;
	min = find_min(s->a, st_a);
	max = find_max(s->a, st_a);
	s->max_case = 0;
	s->min_case = 0;
	while ((st_b_tmp <= rc_b + st_b) && s->a[st_a + rc_a + 1] != NULL)
	{
		if (s->a[st_a + rc_a]->num > s->a[st_a + rc_a + 1]->num &&
				((s->b[st_b + rc_b]->num > s->a[max]->num) || (s->b[st_b + rc_b]->num < s->a[min]->num)))
		{
//			ft_printf("CUT\n", rc_a, rc_b);
			if (rc_b > rc_b_max)
				rc_b_max = rc_b;
//			return (rc_b);
		}
		if (s->b[st_b + rc_b]->num > s->a[st_a + rc_a]->num)
		{
			if (s->b[st_b + rc_b]->num < s->a[st_a + rc_a + 1]->num)
			{
	//		ft_printf("!rc_a =%d, rc_b =%d\n", rc_a, rc_b);
			if (rc_b > rc_b_max)
				rc_b_max = rc_b;
//			return (rc_b);
			}
		}
		--rc_b;
	}
	return (rc_b_max);
}

long long int	n_commands(int rc_a, t_stacks *s, int st_a, int st_b)
{
	int				rc_b;
	long long int	rc_b_min;
	int				min;
	int				max;

	rc_b = 0;
	rc_b_min = LLONG_MAX - 2;
	min = find_min(s->a, st_a);
	max = find_max(s->a, st_a);
	s->max_case = 0;
	s->min_case = 0;
	if (rc_a == -1)
	{
		while (s->b[st_b + rc_b] != NULL)
		{
//			ft_printf("num is: %d\nbetween =%d:%d\n", s->b[st_b + rc_b]->num, s->a[s->size - 1]->num, s->a[st_a]->num);
//			ft_printf("rc_a =%d, rc_b =%d\n", rc_a, rc_b);
			if (s->a[s->size - 1]->num > s->a[st_a]->num &&
					((s->b[st_b + rc_b]->num > s->a[max]->num) || (s->b[st_b + rc_b]->num < s->a[min]->num)))
			{
//				ft_printf("found\n", rc_a, rc_b);
				if (rc_b < rc_b_min)
					rc_b_min = rc_b;
//				return (rc_b);
			}
			else if (s->b[st_b + rc_b]->num > s->a[s->size - 1]->num)
			{
				if (s->b[st_b + rc_b]->num < s->a[st_a]->num)
				{
					if (rc_b < rc_b_min)
						rc_b_min = rc_b;
				}
			}
			++rc_b;
		}
//		ft_printf("!rc_b_min =%lld\n",rc_b_min);
		return (rc_b_min);
	}
	while (s->b[st_b + rc_b] != NULL && s->a[st_a + rc_a + 1] != NULL)
	{
//		ft_printf("num is: %d\nbetween =%d:%d, min is %d, max is %d\n",
///				s->b[st_b + rc_b]->num, s->a[st_a + rc_a]->num, s->a[st_a + rc_a + 1]->num,
//				s->a[min]->num, s->a[max]->num);
//		ft_printf("rc_a =%d, rc_b =%d\n", rc_a, rc_b);
		if (s->a[st_a + rc_a]->num > s->a[st_a + rc_a + 1]->num &&
				((s->b[st_b + rc_b]->num > s->a[max]->num) || (s->b[st_b + rc_b]->num < s->a[min]->num)))
		{
//			ft_printf("found\n");
				if (rc_b < rc_b_min)
					rc_b_min = rc_b;
//			return (rc_b);
		}
		if (s->b[st_b + rc_b]->num > s->a[st_a + rc_a]->num)
		{
			if (s->b[st_b + rc_b]->num < s->a[st_a + rc_a + 1]->num)
			{
	//		ft_printf("!rc_a =%d, rc_b =%d\n", rc_a, rc_b);
				if (rc_b < rc_b_min)
					rc_b_min = rc_b;
//			return (rc_b);
			}
		}
		++rc_b;
	}
//	ft_printf("!rc_b_min =%lld\n",rc_b_min);
	return (rc_b_min);
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
	if (index < (s->size / 2))
		f_all_i(s, index, "ra");
	else
		f_all_i(s, s->size - index, "rra");
}


/*
int		(t_stacks *s, int st_a, int st_b)
{
}

int		max_mid_min012(t_stacks *s, int st_a, int st_b)
{
	int	max;
	int	min;


	while (s->b[st_b] != NULL && s->a[st_a] != NULL)
	{
		if (s->b[st_b + rc_b]->num < s->a[st_a + rc_a]->num)
		{
			return (rc_b);
		}
		++rc_b;
	}
}
*/


long long int	find_sp_min(t_stacks *s, long long int *s_rc_a, int st_a, int st_b)
{
	long long int	s_rc_b;
	int				min_b;
	int				min;
	int				max;

	min = find_min(s->a, st_a);
	max = find_max(s->a, st_a);
	min_b = find_min(s->b, st_b);
	s_rc_b = st_b - min_b;
	if (max == (s->size - 1) && (min == st_a))
		*s_rc_a = 0;
	else
		*s_rc_a = max - st_a;
	return (s_rc_b);
}

long long int	find_sp_max(t_stacks *s, long long int *s_rc_a, int st_a, int st_b)
{
	long long int	s_rc_b;
	int				max_b;
	int				min;
	int				max;

	min = find_min(s->a, st_a);
	max = find_max(s->a, st_a);
	max_b = find_max(s->b, st_b);
	s_rc_b = st_b - max_b;
	if (max == (s->size - 1) && (min == st_a))
		*s_rc_a = 0;
	else
		*s_rc_a = max - st_a;
	return (s_rc_b);
}

int		sp_is_min(long long int s_rc_a, long long int s_rc_b, int rc_a, int rc_b)
{
	long long int		max_s;
	int					max_n;

	if (s_rc_a > s_rc_b)
		max_s = s_rc_a;
	else
		max_s = s_rc_b;
	if (rc_a > rc_b)
		max_n = rc_a;
	else
		max_n = rc_b;
	if (max_n < max_s)
		return (0);
	else
		return (1);
}

long long int		max_between_two(long long int n1, long long int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

void	push_one_back(t_stacks *s, int size, int *cut)
{
	int		st_a;
	int		st_b;
//	int		i;
	int		rc_a;
	int		rc_a_tmp;
	int		rc_b;
	long long int		min;
	long long int		pret;
	long long int		sp_rc_a;
	long long int		sp_rc_b;

	min = LLONG_MAX - 2;
	sp_rc_a = LLONG_MAX;
	sp_rc_b = LLONG_MAX;
	st_a = get_first_id(s->a);
	st_b = get_first_id(s->b);
//	ft_printf("starta =%d, startb =%d\n", st_a, st_b);
	/*
	if (s->a[st_a]->num > s->b[st_b]->num)
	{
		f_all("pa", s->a, s->b);
		return ;
	}
*/
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
	rc_a = -1;
	rc_b = 0;
	int		flag = 0;
//	ft_printf("%d<=%d\n", rc_a, size / 2);
	while ((rc_a) <= (size / 2))
	{
//		ft_printf("%d<=%d\n", rc_a, size / 2);
		/*
		if (s->a[st_a + rc_a]->num > s->a[st_a + rc_a + 1]->num)
		{
			break ;
		}
		*/
		
		pret = n_commands(rc_a, s, st_a, st_b);
		/*
		if (pret == LLONG_MAX - 0)
		{
			ft_printf("min\n");
			sp_rc_b = find_sp_min(s, &sp_rc_a, st_a, st_b);
		}
		else if (pret == LLONG_MAX - 1)
		{
			sp_rc_b = find_sp_max(s, &sp_rc_a, st_a, st_b);
		}
		*/
		/*
		if (pret <= rc_a || (rc_a == 0 && pret == 1))
		{
			push_it_back(rc_a, pret, s);
			return ;
		}
		*/
		if (max_between_two(rc_a, pret) < max_between_two(rc_a_tmp, min))
		{
			rc_a_tmp = rc_a;
			min = pret;
		}
		/*
		if (pret < min)
		{
			rc_a_tmp = rc_a;
			min = pret;
		}
		*/
//		ft_printf("res:rc_a =%lld, rc_b =%lld\n, pret = %lld\n", rc_a_tmp + 1, min, pret);
		++rc_a;
	}
	while ((rc_a) < size) // 2)
	{
//		ft_printf("%d<=%d\n", rc_a, size);
		pret = n_commands_rev(rc_a, s, st_a, st_b) - 1; // -1
		if (pret < 0)
			pret *= -1;
		if (max_between_two(rc_a, pret) < max_between_two(rc_a_tmp, min))
		{
			rc_a_tmp = rc_a;
			min = pret;
		}
		/*
		if (pret < min)
		{
			flag = 1;
			rc_a_tmp = rc_a;
			min = pret;
		}
		*/
	//	ft_printf("res:rc_a =%lld, rc_b =%lld\n, pret = %lld\n", rc_a_tmp + 1, min, pret);
		++rc_a;
	}
	/*
		if (pret == (INT_MAX))
		{
			f_all("pa", s->a, s->b);
			f_all("ra", s->a, s->b);
			return ;
		}
		*/
	/*
	if (sp_is_min(sp_rc_a, sp_rc_b, rc_a_tmp, min))
	{
		ft_printf("spmin%d, %d\n", sp_rc_a, sp_rc_b);
		push_it_back(sp_rc_a, sp_rc_b, s);
	}
	else
	{
		push_it_back(rc_a_tmp, min, s);
	}
	*/
	if (!flag)
	{
//	ft_printf("turn:rc_a =%lld, rc_b =%lld\n", rc_a_tmp + 1, min);
		push_it_back(rc_a_tmp + 1, min, s);
	}
	else
	{
//	ft_printf("turn:rc_a =%lld, rc_b =%lld\n", size - (rc_a_tmp + 1), min);
		push_it_back_rev(size - (rc_a_tmp + 1), min, s);
	}
//	else
//		f_all_i(s, 1, "pa");
	*cut = find_min(s->a, st_a);
//	ft_printf("min = %d\n", *cut);
	*cut = find_max(s->a, st_a);
//	ft_printf("max = %d\n", *cut);
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
//		print_stks(s->a, s->b);
	i = 0;
	size_ext = 3;
	while (i < size - 3)
	{
		push_one_back(s, size_ext, &cut);
//		print_stks(s->a, s->b);
		i++;
		size_ext++;
	}
	correction(s);
//		print_stks(s->a, s->b);
//	push_back(s->a, s->b, size - size_ext);
}
