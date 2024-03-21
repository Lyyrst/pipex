/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:47:03 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/16 12:06:02 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstclear(t_gnl **list)
{
	t_gnl	*temp;
	t_gnl	*p_list;

	p_list = *list;
	while (p_list)
	{
		free(p_list->content);
		temp = p_list->next;
		free(p_list);
		p_list = temp;
	}
}

t_gnl	*lstlast(t_gnl *list)
{
	if (list == 0)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int	new_line(t_gnl *list)
{
	t_gnl	*p_list;
	int		i;

	i = 0;
	if (list == 0)
		return (0);
	p_list = lstlast(list);
	while (p_list->content[i])
	{
		if (p_list->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	line_len(t_gnl *list)
{
	int	count;
	int	i;

	count = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				count++;
				break ;
			}
			count++;
			i++;
		}
		list = list->next;
	}
	return (count);
}
