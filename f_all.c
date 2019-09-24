/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:41:45 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:03:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

void	f_all_mult(const char *c1, const char *c2,
		t_elem **a, t_elem **b)
{
	if (c1)
		f_all(c1, a, b);
	if (c2)
		f_all(c2, a, b);
}

void	f_all3(const char *com, t_elem **a, t_elem **b)
{
	if (ft_strequ(com, "rra") == 1)
	{
		f_rra(a);
		ft_putstr("rra\n");
	}
	else if (ft_strequ(com, "rrb") == 1)
	{
		f_rra(b);
		ft_putstr("rrb\n");
	}
	else if (ft_strequ(com, "rrr") == 1)
	{
		f_rrr(a, b);
		ft_putstr("rrr\n");
	}
}

void	f_all2(const char *com, t_elem **a, t_elem **b)
{
	if (ft_strequ(com, "pb") == 1)
	{
		f_pa(b, a);
		ft_putstr("pb\n");
	}
	else if (ft_strequ(com, "ra") == 1)
	{
		f_ra(a);
		ft_putstr("ra\n");
	}
	else if (ft_strequ(com, "rb") == 1)
	{
		f_ra(b);
		ft_putstr("rb\n");
	}
	else if (ft_strequ(com, "rr") == 1)
	{
		f_rr(a, b);
		ft_putstr("rr\n");
	}
	f_all3(com, a, b);
}

void	f_all(const char *com, t_elem **a, t_elem **b)
{
	if (ft_strequ(com, "sa") == 1)
	{
		f_sa(a);
		ft_putstr("sa\n");
	}
	else if (ft_strequ(com, "sb") == 1)
	{
		f_sa(b);
		ft_putstr("sb\n");
	}
	else if (ft_strequ(com, "ss") == 1)
	{
		f_ss(a, b);
		ft_putstr("ss\n");
	}
	else if (ft_strequ(com, "pa") == 1)
	{
		f_pa(a, b);
		ft_putstr("pa\n");
	}
	f_all2(com, a, b);
}
