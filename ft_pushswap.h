/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:43 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/19 23:04:42 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

typedef struct		t_elem
{
	int				num;
	int				empty;
}					t_elem;

typedef struct		t_stacks
{
	t_elem			**a;
	t_elem			**b;
	t_elem			**t;
}					t_stacks;

void	ft_swapint(int *a, int *b);
void	f_all(const char *com, t_elem **a, t_elem **b);
void	f_all_mult(const char *com, const char *com2,
		t_elem **a, t_elem **b);
void	f_sa(t_elem **a);
void	f_ss(t_elem **a, t_elem **b);
void	f_pb(t_elem **a, t_elem **b);
void	f_pa(t_elem **a, t_elem **b);
void	f_ra(t_elem **a);
void	f_rra(t_elem **a);
void	f_rrr(t_elem **a, t_elem **b);
void	f_rr(t_elem **a, t_elem **b);
void	f_rra_i(t_elem **a, int i);
void	f_ra_i(t_elem **a, int i);

t_elem	*new_elem(int num, int empty);
t_elem	**new_arr_elem(int size);
int		ft_strisdig(char *str);
int		read_push(t_elem **elems, char **argv, int argc);
int		sort_elems(t_elem **a, int size);
void	print_stks(t_elem **a, t_elem **b);


void	move_pair(int e1, int e2, t_stacks *s, int size_ext);
int		is_wrong(t_elem **a);
int		find_indexes(t_elem **a, int e1, int e2, int *i2);

#endif
