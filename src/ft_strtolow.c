/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:27:18 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 20:57:51 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtolow(char *s)
{
	char *hld;

	hld = s;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	return (hld);
}
