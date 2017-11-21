/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:47:04 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/03 14:10:38 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_itoa(int n)
{
	char	*new;
	int		len;
	int		start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (n < 0) ? ft_digitcount(n * -1) + 1 : ft_digitcount(n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	start = (n < 0);
	if (n < 0)
	{
		n *= -1;
		new[0] = '-';
	}
	len--;
	while (len >= start)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (new);
}
