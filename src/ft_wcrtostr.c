/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:15:02 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/08 19:20:09 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "../inc/libft.h"

char	*ft_wcrtostr(const wchar_t *wide)
{
	char	*new;
	int		i;
	int		j;
	char	c;
	
	new = ft_strnew(sizeof(wchar_t) * ft_wstrlen(wide));
	i = 0;
	while (wide[i])
	{
		j = 0;
		while (j < sizeof(wchar_t))
		{
			c = (wide[i] >> ((sizeof(wchar_t) - j - 1) * 8)) & 0xff;
			new[(i * sizeof(wchar_t)) + j] = c;
			j++;
		}
		i++;
	}
	return (new);
}
