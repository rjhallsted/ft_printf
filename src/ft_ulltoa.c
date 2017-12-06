/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:39:42 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 11:41:21 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char	*new;
	int		len;

	len = ft_digitcount(n);
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	while (len-- > 0)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
