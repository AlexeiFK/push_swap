/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:09:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/17 18:43:30 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_stack
{
	t_list			*elem;
	int				size;
}					t_stack;

typedef struct		t_elem
{
	int				num;
	int				empty;
}					t_elem;

void	ft_lstiter2(t_list *lst, t_list *lst2, void (*f)(t_list *elem, t_list *elem2));
void	*ft_stackpop(t_stack *stack);
void	*ft_stackpush(t_stack *stack, void *content);
void	*ft_stackprint(t_stack *stack);
