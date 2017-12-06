/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:24:02 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/05 20:14:10 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../inc/libft.h"

char		*ft_ltoa(long n)
{
	char	*new;
	int		len;
	int		start;
	int		mod_by;
	int		tmp;

	tmp = (n == LONG_MIN) ? n + 1 : n;
	len = (n < 0) ? ft_digitcount(n * -1) + 1 : ft_digitcount(n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		new[0] = '-';
	start = (n < 0);
	mod_by = (n < 0) ? -10 : 10;
	while (len-- > start)
	{
		new[len] = (n % mod_by) + '0';
		n /= 10;
	}
	return (new);
}
