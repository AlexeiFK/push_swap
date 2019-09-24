/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:46:52 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:09:14 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"
#include <stdlib.h>

void	free_elems(t_elem **e)
{
	int		i;

	i = 0;
	while (e[i] != NULL)
	{
		free(e[i]);
		i++;
	}
	free(e);
}

void	free_my_stacks(t_stacks *s)
{
	free_elems(s->a);
	free_elems(s->b);
	free_elems(s->t);
}

int		free_stacks_ret_zero(t_stacks *s)
{
	free_my_stacks(s);
	return (0);
}
