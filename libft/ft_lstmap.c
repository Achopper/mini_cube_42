/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:40:39 by achopper          #+#    #+#             */
/*   Updated: 2020/11/19 19:37:21 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*elem;

	res = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (NULL == elem)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&res, elem);
		lst = lst->next;
	}
	return (res);
}
