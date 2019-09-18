/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:43 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/18 18:41:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

typedef struct		t_elem
{
	int				num;
	int				empty;
}					t_elem;

void	ft_swapint(int *a, int *b);
void	f_all(const char *com, t_elem **a, t_elem **b);
void	f_sa(t_elem **a);
void	f_ss(t_elem **a, t_elem **b);
void	f_pb(t_elem **a, t_elem **b);
void	f_pa(t_elem **a, t_elem **b);
void	f_ra(t_elem **a);
void	f_rra(t_elem **a);
void	f_rrr(t_elem **a, t_elem **b);
void	f_rr(t_elem **a, t_elem **b);

#endif
