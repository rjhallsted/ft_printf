/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:01:32 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/13 18:07:09 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

int	ft_strinsert(char *outer, const char *inner, size_t pos)
{
	int inner_len;
	int i;
	
	inner_len = ft_strlen(inner);
	ft_memmove(outer + pos, outer, ft_strlen(outer + pos));
	i = 0;
	while (i < inner_len)
	{
		outer[pos + i] = inner[i];
		i++;
	}
	return (ft_strlen(outer));
}
