/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:35:53 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/17 18:40:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter2(t_list *lst, t_list *lst2, void (*f)(t_list *elem, t_list *elem2))
{
	while (lst && lst2)
	{
		(*f)(lst, lst2);
		lst = lst->next;
		lst2 = lst2->next;
	}
}
