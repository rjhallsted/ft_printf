/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:15:02 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/08 23:41:39 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "../inc/libft.h"

char	*ft_wcrtostr(const wchar_t *wide)
{
	char			*new;
	int				i;
	int				j;
	unsigned char 	c;
	
	new = ft_strnew(WCHAR_SIZE * ft_wstrlen(wide));
	i = 0;
	while (wide[i])
	{
		j = 0;
		while (j < WCHAR_SIZE)
		{
			c = (wide[i] >> ((WCHAR_SIZE - j) * 8)) & 0xff;
			new[(i * WCHAR_SIZE) + j] = c;
			j++;
		}
		i++;
	}
	return (new);
}
