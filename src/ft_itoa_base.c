/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:53:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:25:16 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_itoa_base(int n, unsigned int base)
{
	char	*new;
	char	*base_key;
	int		len;

	if (base == 10)
		return (ft_itoa(n));
	base_key = "0123456789abcdef";
	len = ft_digitcount_base((UNSI)n, base);
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	len--;
	while (len >= 0)
	{
		new[len] = base_key[n % (int)base];
		n /= base;
		len--;
	}
	return (new);
}
