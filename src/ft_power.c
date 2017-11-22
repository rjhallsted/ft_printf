/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:40:31 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:25:32 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_power(int base, int power)
{
	int i;
	int	nb;

	i = 1;
	nb = 1;
	while (i <= power)
	{
		nb *= base;
		i++;
	}
	return (nb);
}
