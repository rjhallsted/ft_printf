/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:58:44 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:23:23 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_digitcount_base(unsigned int n, unsigned int base)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}
