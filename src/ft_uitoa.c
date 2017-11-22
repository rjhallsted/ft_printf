/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:23:24 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 14:27:48 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_uitoa(unsigned int n)
{
	char	*new;
	int		len;

	len = ft_digitcount(n);
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	len--;
	while (len >= 0)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (new);
}
