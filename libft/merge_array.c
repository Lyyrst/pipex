/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:13:58 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/08 18:17:21 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**merge_array(char **arr1, char **arr2, char *str1, char *str2)
{
	char	**ret_arr;
	char	**line1;
	char	**line2;
	int		i;
	int		j;

	line1 = ft_split(str1, ' ');
	line2 = ft_split(str2, ' ');
	ret_arr = malloc(sizeof(char *) * (ft_arraylen(line1)
				+ ft_arraylen(line2) + 1));
	i = 0;
	j = 0;
	while (line1[i])
		ret_arr[j++] = arr1[ft_atoi(line1[i++])];
	i = 0;
	while (line2[i])
		ret_arr[j++] = arr2[ft_atoi(line2[i++])];
	ret_arr[j] = 0;
	return (ret_arr);
}
