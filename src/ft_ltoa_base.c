/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:21:59 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/04 14:26:02 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_ltoa_base(long n, unsigned int base)
{
	char	*new;
	char	*base_key;
	int		len;

	if (base == 10)
		return (ft_itoa(n));
	base_key = "0123456789abcdef";
	len = ft_digitcount_base((unsigned long)n, base);
	if (!(new = ft_strnew(len) (NULL);
	len--;
	while (len >= 0)
	{
		new[len] = base_key[n % (int)base];
		n /= base;
		len--;
	}
	return (new);
}
