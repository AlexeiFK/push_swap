/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/18 22:38:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

#include <limits.h>
#include <stdlib.h>

t_elem	*new_elem(int num, int empty)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->num = num;
	new->empty = empty;
	return (new);
}

t_elem	**new_arr_elem(int size)
{
	t_elem	**new;
	int		i;

	i = 0;
	if (!(new = (t_elem**)malloc(sizeof(t_elem*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new[i] = new_elem(i, 1);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		ft_strisdig(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_isdigit(str[i]) == 0 && str[i] != '-')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		if (i >= 12)
			return (0);
		i++;
	}
	return (1);
}

int		read_push(t_elem **elems, char **argv, int argc)
{
	int				i;
	long long int	tmp;

	i = 1;
	while (i < argc)
	{
		if (ft_strisdig(argv[i]) == 0)
			return (0);
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		elems[i - 1]->num = tmp; 
		elems[i - 1]->empty = 0;
		i++;
	}
	return (1);
}

int		sort_elems(t_elem **a, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (a[j]->num > a[j + 1]->num)
				ft_swapint(&a[j]->num, &a[j + 1]->num);
			j++;
		}
		i++;
	}
	while (i > (size / 2))
	{
		i--;
	}
	return (a[i]->num);
}

void	print_stks(t_elem **a, t_elem **b)
{
	int		i;

	ft_printf("\n");
	i = 0;
	while (a[i] != NULL)
	{
		ft_printf("[%d]", i);
		if (a[i]->empty == 0)
			ft_printf("%12d", a[i]->num);
		else
			ft_printf("%12s", "-");
		ft_printf(" ");
		if (b[i]->empty == 0)
			ft_printf("%12d", b[i]->num);
		else
			ft_printf("%12s", "-");
		ft_printf("\n");
		i++;
	}
	ft_printf("--------------\n");
}

void	f_rra_i(t_elem **a, int i)
{
	while (i > 0)
	{
		f_all("rra", a, NULL);
		--i;
	}
}

void	f_ra_i(t_elem **a, int i)
{
	while (i > 0)
	{
		f_all("ra", a, NULL);
		--i;
	}
}

int		is_wrong(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL && a[i]->empty != 0)
		i++;
	if (a[i] == NULL || a[i + 1] == NULL)
		return (0);
	if (a[i]->num < a[i + 1]->num)
		return (1);
	else
		return (0);
}

void	move_pair(int e1, int e2, t_elem **a, t_elem **b, int size_ext)
{
	int		i;
	int		j;
	int		ind1;
	int		ind2;
	int		len1;
	int		len2;
	int		flag;
	int		size;

	i = 0;
	flag = 0;
	j = 0;
	size = size_ext;
	while (a[i] != NULL)
	{
		if (e1 == a[i]->num && a[i]->empty != 1)
			ind1 = j;
		if (e2 == a[i]->num && a[i]->empty != 1)
			ind2 = j;
		if (a[i]->empty == 0)
			j++;
		i++;
	}
	if ((size - ind1) > ind1)
		len1 = ind1;
	else
		len1 = size - ind1;
	if ((size - ind2) > ind2)
		len2 = ind2;
	else
		len2 = size - ind2;
	if (len1 < len2)
	{
		if ((size - ind1) > ind1)
		{
			f_ra_i(a, len1);
		}
		else
		{
			f_rra_i(a, len1);
		}
		flag = 1;
	}
	else
	{
		if ((size - ind2) > ind2)
		{
			f_ra_i(a, len2);
		}
		else
		{
			f_rra_i(a, len2);
		}
		flag = 2;
	}
//	print_stks(a, b);
	f_all("pb", a, b);
	size--;
	i = 0;
	j = 0;
	while (a[i] != NULL)
	{
		if (e1 == a[i]->num && a[i]->empty != 1 && flag == 2)
			ind1 = j;
		if (e2 == a[i]->num && a[i]->empty != 1 && flag == 1)
			ind2 = j;
		if (a[i]->empty == 0)
			j++;
		i++;
	}
	if (flag == 1)
	{
		if ((size - ind2) > ind2)
			len2 = ind2;
		else
			len2 = size - ind2;
		if ((size - ind2) > ind2)
		{
			f_ra_i(a, len2);
		}
		else
		{
			f_rra_i(a, len2);
		}
	}
	else if (flag == 2)
	{
		if ((size - ind1) > ind1)
			len1 = ind1;
		else
			len1 = size - ind1;
		if ((size - ind1) > ind1)
		{
			f_ra_i(a, len1);
		}
		else
		{
			f_rra_i(a, len1);
		}
	}
//	print_stks(a, b);
	f_all("pb", a, b);
	if (is_wrong(b) == 1)
		f_all("sb", a, b);
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

void	push_swap(t_elem **a, t_elem **b, t_elem **t, int size)
{
	int		e1;
	int		e2;
	int		i;
	int		size_ext;

	i = 0;
	size_ext = size;
	while (i < size - 1)
	{
		e1 = t[i]->num;
		e2 = t[i + 1]->num;
//		ft_printf("pair = %d,%d\n", e1, e2);
		move_pair(e1, e2, a, b, size_ext);
		size_ext -= 2;
		i += 2;
//	print_stks(a, b);
	}
	if (size % 2 == 1)
	{
		f_all("pb", a, b);
	}
//	print_stks(a, b);
	push_back(a, b, size);
//	print_stks(a, b);
}

int		main(int argc, char **argv)
{
	t_elem	**a;
	t_elem	**b;
	t_elem	**t;
	int		i;
	int		size;
	int		ret;

	size = argc - 1;
	a = new_arr_elem(size);
	b = new_arr_elem(size);
	t = new_arr_elem(size);
	ret = read_push(a, argv, argc);
	read_push(t, argv, argc);
	//ft_printf("ret = %d\n", ret);
	sort_elems(t, size);
	i = 0;
	while (i < size)
	{
	//	ft_printf("%d ", t[i]->num);
		i++;
	}
//	print_stks(a, b);
	push_swap(a, b, t, size);
	print_stks(a, b);
	/*
	print_stks(a, b);
	f_all("sa", a, b);
	print_stks(a, b);
	f_all("pb", a, b);
	f_all("pb", a, b);
	f_all("pb", a, b);
	print_stks(a, b);
	f_all("ra", a, b);
	f_all("rb", a, b);
	print_stks(a, b);
	f_all("rra", a, b);
	f_all("rrb", a, b);
	print_stks(a, b);
	f_all("sa", a, b);
	print_stks(a, b);
	f_all("pa", a, b);
	f_all("pa", a, b);
	f_all("pa", a, b);
	print_stks(a, b);
	*/
	return (0);
}
