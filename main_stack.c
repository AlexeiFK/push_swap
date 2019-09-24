/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:07:51 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

static int	error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;

	size = 0;
	if (argc < 2)
		return (0);
	if (read_argv(&stacks, argv, argc, &size) == 0)
		return (error_msg());
	if (!is_sorted_stacks(&stacks, size))
		push_swap(&stacks, size);
	free_my_stacks(&stacks);
	return (0);
}
