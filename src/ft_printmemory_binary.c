/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory_binary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:55:17 by rhallste          #+#    #+#             */
/*   Updated: 2018/11/08 20:10:44 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libft.h"

static void	put_binary(int a)
{
	char	*str;
	int		len;
	
	str = ft_itoa_base(a, 2);
	len = ft_strlen(str);
	write(1, "00000000", 8 - len);
	write(1, str, len);
	free(str);
}

static void	put_spacing(int a)
{
	while (a < 16)
	{
		if (a % 2 == 1)
		{
			write(1, "   ", 3);
			a++;
		}
		write(1, "     ", 5);
		a += 2;
	}
}

void		ft_printmemory_binary(const void *addr, size_t size)
{
	const unsigned char	*mem;
	size_t				i;
	size_t				tmp;
	unsigned char		c;

	i = 0;
	mem = (const unsigned char *)addr;
	while (i < size)
	{
		tmp = i;
		while (tmp < size && (tmp - i) < 16)
		{
			put_binary(mem[tmp++]);
			if (tmp % 4 == 0)
				write(1, " ", 1);
		}
		if (tmp - i < 16)
			put_spacing((int)(tmp - i));
		while (++i <= tmp)
		{
			c = (ft_isprint(mem[i - 1])) ? *(mem + i - 1) : '.';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}
