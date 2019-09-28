/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:43 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/28 22:20:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# define BAD_MAX -9223372036854775806
# define BAD_MIN 9223372036854775805

typedef struct			s_elem
{
	int					num;
	int					empty;
}						t_elem;

typedef struct			 s_res
{
	int					flag;
	int					rc_a_tmp;
	long long int		min;
	long long int		pret;
}						t_res;

typedef struct	s_stacks
{
	t_elem				**a;
	t_elem				**b;
	t_elem				**t;
	int					size;
}						t_stacks;

long long int			n_commands_rev(int rc_a, t_stacks *s, int st_a, int st_b);
long long int			n_commands(int rc_a, t_stacks *s, int st_a, int st_b);
void					ft_swapint(int *a, int *b);
int						f_all_s(const char *com, t_elem **a, t_elem **b);
void					f_all(const char *com, t_elem **a, t_elem **b);
void					f_all_mult(const char *com, const char *com2,
						t_elem **a, t_elem **b);
void					f_sa(t_elem **a);
void					f_ss(t_elem **a, t_elem **b);
void					f_pb(t_elem **a, t_elem **b);
void					f_pa(t_elem **a, t_elem **b);
void					f_ra(t_elem **a);
void					f_rra(t_elem **a);
void					f_rrr(t_elem **a, t_elem **b);
void					f_rr(t_elem **a, t_elem **b);
void					f_rra_i(t_elem **a, int i);
void					f_all_i(t_stacks *s, int i, const char *str);
void					f_ra_i(t_elem **a, int i);

t_elem					*new_elem(int num, int empty);
t_elem					**new_arr_elem(int size);
void					free_elems(t_elem **e);
void					free_my_stacks(t_stacks *s);
int						free_stacks_ret_zero(t_stacks *s);
int						ft_strisdig(char *str);
int						read_push(t_elem **elems, char **argv, int argc);
int						is_sorted_stacks(t_stacks *s, int size);
int						sort_elems(t_elem **a, int size);
void					print_stks(t_elem **a, t_elem **b);
int						read_argv(t_stacks *s, char **argv,
						int argc, int *new_size);
void					push_swap(t_stacks *s, int size);
void					push_swap_new(t_stacks *s, int size);
int						find_min(t_elem **a, int st_a);
int						find_max(t_elem **a, int st_a);
void					push_swap_special(t_stacks *s, int size);
void					push_one_back(t_stacks *s, int size);
void					push_it_back(int rc_a, int rc_b, t_stacks *s);
void					push_it_back_rev(int rc_a, int rc_b, t_stacks *s);
long long int			max_between_two(long long int n1, long long int n2);


void					move_pair(int e1, int e2, t_stacks *s, int size_ext);
int						is_wrong(t_elem **a);
int						get_first_id(t_elem **a);
int						find_indexes(t_elem **a, int e1, int e2, int *i2);

#endif
