/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:29:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 11:27:45 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../inc/libft.h"

char		*ft_lltoa(long long n)
{
	char		*new;
	int			len;
	int			start;
	int			mod_by;
	long long	tmp;

	tmp = (n == LLONG_MIN) ? n + 1 : n;
	len = (n < 0) ? ft_digitcount(tmp * -1) + 1 : ft_digitcount(tmp);
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		new[0] = '-';
	start = (n < 0);
	mod_by = (n < 0) ? -10 : 10;
	while (len-- > start)
	{
		new[len] = ((n % mod_by) * (mod_by / 10))  + '0';
		n /= 10;
	}
	return (new);
}
