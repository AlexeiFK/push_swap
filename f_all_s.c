/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:22:46 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/24 18:04:22 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pushswap.h"

int	f_all3_s(const char *com, t_elem **a, t_elem **b)
{
	if (ft_strequ(com, "rra") == 1)
	{
		f_rra(a);
		return (1);
	}
	else if (ft_strequ(com, "rrb") == 1)
	{
		f_rra(b);
		return (1);
	}
	else if (ft_strequ(com, "rrr") == 1)
	{
		f_rrr(a, b);
		return (1);
	}
	return (0);
}

int	f_all2_s(const char *com, t_elem **a, t_elem **b)
{
	if (ft_strequ(com, "pb") == 1)
	{
		f_pa(b, a);
		return (1);
	}
	else if (ft_strequ(com, "ra") == 1)
	{
		f_ra(a);
		return (1);
	}
	else if (ft_strequ(com, "rb") == 1)
	{
		f_ra(b);
		return (1);
	}
	else if (ft_strequ(com, "rr") == 1)
	{
		f_rr(a, b);
		return (1);
	}
	return (f_all3_s(com, a, b));
}

int	f_all_s(const char *com, t_elem **a, t_elem **b)
{
	if (ft_strequ(com, "sa") == 1)
	{
		f_sa(a);
		return (1);
	}
	else if (ft_strequ(com, "sb") == 1)
	{
		f_sa(b);
		return (1);
	}
	else if (ft_strequ(com, "ss") == 1)
	{
		f_ss(a, b);
		return (1);
	}
	else if (ft_strequ(com, "pa") == 1)
	{
		f_pa(a, b);
		return (1);
	}
	return (f_all2_s(com, a, b));
}
