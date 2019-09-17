/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:27:01 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/17 19:36:53 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"

#include <stdlib.h>
#include <stdio.h>

void	print_list(t_list *lst)
{
	static int	i = 0;
	t_elem		*elem;

	elem = (t_elem*)lst->content;
	ft_printf("[%d]%d - empty = %d\n", i, elem->num, elem->empty);
	i++;
}

void	print_list2(t_list *lst1, t_list *lst2)
{
	t_elem		*elem1;
	t_elem		*elem2;

	elem1 = (t_elem*)lst1->content;
	elem2 = (t_elem*)lst2->content;
	if (elem1->empty == 0)
		ft_printf("%d", elem1->num);
	else
		ft_printf("-");
	ft_printf(" | ");
	if (elem2->empty == 0)
		ft_printf("%d", elem2->num);
	else
		ft_printf("-");
	ft_printf("\n");
}

void	del_stack(void *mem, size_t size)
{
	if (size == sizeof(t_elem))
	{
		free(mem);
	}
}

void	f_sa(t_list *a)
{
	void	*tmp;
	t_elem  *elem;
	t_elem  *elem_next;

	elem = (t_elem*)a->content;
	while (a->next && (elem->empty == 1))
	{
		elem = (t_elem*)a->content;
		a = a->next;
	}
	if (a->next)
	{
		elem = (t_elem*)a->content;
		elem_next = (t_elem*)a->next->content;
		if (elem->empty == 0 & elem_next->empty == 0)
		{
			tmp = a->content;
			a->content = a->next->content;
			a->next->content = tmp;
		}
	}
}

void	f_ss(t_list *a, t_list *b)
{
	f_sa(a);
	f_sa(b);
}

void	f_pa(t_list	*a, t_list *b)
{
	void	*tmp;
	t_elem  *elem_a;
	t_elem  *elem_b;

	elem_a = (t_elem*)a->content;
	while (a && (elem_a->empty == 1))
	{
		elem_a = (t_elem*)a->content;
		a = a->next;
	}
	elem_b = (t_elem*)b->content;
	while (b && (elem_b->empty == 1))
	{
		elem_b = (t_elem*)b->content;
		b = b->next;
	}
	if (elem_a->empty != 1)
	{
		elem_b->num = elem_a->num;
		elem_a->empty = 1;
		elem_b->empty = 0;
	}
}

t_elem	*new_elem(int num, int empty)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->num = num;
	new->empty = empty;
	return (new);
}

int		main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*stack2;
	t_list	*tmp;
	t_elem	*elem;
	int		i;
	int		n;

	i = 1;
	n = 10;
	elem = new_elem(i, 0);
	stack = ft_lstnew(elem, sizeof(t_elem));
	free(elem);
	i++;
	while (i < n)
	{
		elem = new_elem(i, 0);
		tmp = ft_lstnew(elem, sizeof(t_elem));
		ft_lstadd(&stack, tmp);
		free(elem);
		i++;
	}
	i = 11;
	n = 20;
	elem = new_elem(i*i, 1);
	stack2 = ft_lstnew(elem, sizeof(t_elem));
	free(elem);
	i++;
	while (i < n)
	{
		elem = new_elem(i * i, 1);
		tmp = ft_lstnew(elem, sizeof(t_elem));
		free(elem);
		ft_lstadd(&stack2, tmp);
		i++;
	}
	ft_lstiter2(stack, stack2, &print_list2);
	ft_printf("-------------\n");
	f_sa(stack);
	f_pa(stack, stack2);
	f_pa(stack, stack2);
	ft_lstiter2(stack, stack2, &print_list2);
	ft_lstdel(&stack, &del_stack);
	ft_lstdel(&stack2, &del_stack);
	return (0);
}
