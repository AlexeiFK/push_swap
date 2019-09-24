/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:09:57 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:07:38 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "ft_pushswap.h"
#include <stdlib.h>

static int	error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int			push_checker(t_stacks *s, int size)
{
	char	*str;

	while (get_next_line(0, &str) > 0)
	{
		if (f_all_s(str, s->a, s->b) == 0)
		{
			free(str);
			free_my_stacks(s);
			return (error_msg());
		}
		free(str);
	}
	free(str);
	if (is_sorted_stacks(s, size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int			main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;

	if (argc < 2)
		return (0);
	if (read_argv(&stacks, argv, argc, &size) == 0)
		return (error_msg());
	if (push_checker(&stacks, size) == 1)
		free_my_stacks(&stacks);
	return (0);
}
