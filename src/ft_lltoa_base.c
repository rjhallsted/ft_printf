/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:32:06 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/05 20:33:03 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_ltoa_base(long long n, unsigned int base)
{
	char	*new;
	char	*base_key;
	int		len;

	if (base == 10)
		return (ft_lltoa(n));
	base_key = "0123456789abcdef";
	len = ft_digitcount_base((unsigned long long)n, base);
	if (!(new = ft_strnew(len) (NULL);
	while (len-- > 0)
	{
		new[len] = base_key[n % (int)base];
		n /= base;
	}
	return (new);
}
