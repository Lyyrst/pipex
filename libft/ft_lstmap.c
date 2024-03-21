/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:11:22 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/14 14:32:07 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*tmp;

	new = 0;
	if (!lst || !(*f) || !(*del))
		return (0);
	while (lst)
	{
		tmp = (*f)(lst->content);
		node = ft_lstnew(tmp);
		if (!node)
		{
			(*del)(tmp);
			ft_lstclear(&new, (*del));
			return (0);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
