/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:09:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/15 22:49:30 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_stack
{
	t_list			*elem;
	int				size;
}					t_stack;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void	*ft_stackpop(t_stack *stack);
void	*ft_stackpush(t_stack *stack, void *content);
void	*ft_stackprint(t_stack *stack);
