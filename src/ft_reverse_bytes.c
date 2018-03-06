/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bytes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:18 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/05 21:56:30 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

void	ft_reverse_bytes(void *mem, size_t size)
{
	size_t			i;
	unsigned char	*memstr;

	memstr = mem;
	i = 0;
	while (i < size / 2)
	{
		memstr[i] ^= memstr[(size - 1) - i];
		memstr[(size - 1) - i] ^= memstr[i];
		memstr[i] ^= memstr[(size - 1) - i];
		i++;
	}
}
