/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/17 20:39:25 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"

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
	i++;
	if (ft_isdigit(str[i]) == 0 && str[i] != '-')
		return (0);
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
	int				j;
	long long int	tmp;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_strisdig(argv[i]) == 0)
			return (0);
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		elems[j]->num = tmp; 
		elems[j]->empty = 0;
		j++;
		i++;
	}
	return (1);
}

void	ft_swapint(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	f_sa(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i]->empty != 0 && a[i] != NULL)
		i++;
	if (a[i] == NULL || a[i + 1] == NULL)
		return ;
	ft_swapint(&a[i]->num, &a[i + 1]->num);
}

void	f_ss(t_elem **a, t_elem **b)
{
	f_sa(a);
	f_sb(b);
}

void	f_pa(t_elem **a)
{
	int		i;

	i = 0;
	while (a[i]->empty != 0 && a[i] != NULL)
		i++;
	if (a[i] == NULL || a[i + 1] == NULL)
		return ;
	ft_swapint(&a[i]->num, &a[i + 1]->num);
}

int		main(int argc, char **argv)
{
	t_elem	**a;
	t_elem	**b;
	int		i;
	int		size;
	int		ret;

	size = argc - 1;
	a = new_arr_elem(size);
	b = new_arr_elem(size);
	ret = read_push(a, argv, argc);
	ft_printf("ret = %d\n", ret);
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
	f_sa(a);
	f_sa(a);
	f_sa(a);
	f_sa(a);
	f_sa(a);
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
	return (0);
}
