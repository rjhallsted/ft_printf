/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:39:24 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/12 15:17:18 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static int ft_canprint(int a)
{
	return ((a >= ' ' && a <= 126));
}

static void put_hex(int a)
{
	char *hex_key;
	char let1;
	char let2;

	hex_key = "0123456789abcdef";
	let1 = hex_key[a / 16];
	let2 = hex_key[a % 16];
	write(1, &let1, 1);
	write(1, &let2, 1);
}

static void put_spacing(int a)
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

void		ft_printmemory(const void *addr, size_t size)
{
	const unsigned char	*mem;
	size_t				i;
	size_t				tmp;
	
	i = 0;
	mem = (const unsigned char *)addr;
	while (i < size)
	{
		tmp = i;
		while (tmp < size && (tmp - i) < 16)
		{
			put_hex(mem[tmp]);
			tmp++;
			if (tmp % 2 == 0)
				write(1, " ", 1);
		}
		if (tmp - i < 16)
			put_spacing(tmp - i);
		while (i < tmp)
		{
			if (ft_canprint(mem[i]))
				write(1, mem + i, 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
