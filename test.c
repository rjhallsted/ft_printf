/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/23 22:49:05 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

#define LIB_COLOR \e[34m
#define FT_COLOR \e[35m
#define NORM_COLOR \e[0m

int main(void)
{
//	char *test = "test string";
	char *hold;
	hold = ft_strnew(100);
	printf("\e[34mstring: %s\n", "this");
	ft_snprintf(hold, 100, "string: %s\n", "this");
	printf("\e[35m%s\e[0m", hold);
	free(hold);

	hold = ft_strnew(100);
	printf("\e[34mSigned dec: %d\n", 2);
	ft_snprintf(hold, 100, "Signed dec: %d\n", 2);
	printf("\e[35m%s\e[0m", hold);
	free(hold);

	hold = ft_strnew(100);
	printf("\e[34mUnsigned dec: %u, %u\n", 3, 13244214);
	ft_snprintf(hold, 100, "Unsigned dec: %u, %u\n", 3, 13244214);
	printf("\e[35m%s\e[0m", hold);
	free(hold);

	hold = ft_strnew(100);
	printf("\e[34mchar: %c, %c\n", 'a', '/200'); //actual printf doesn't accept capital-C
	ft_snprintf(hold, 100, "char: %c, %C\n", 'a', '/200');
	printf("\e[35m%s\e[0m", hold);
	free(hold);

 	hold = ft_strnew(100);
	printf("\e[34mOctal: %o, %O, %o\n", 1, 23, -64);
	ft_snprintf(hold, 100, "Octal: %o, %O, %o\n", 1, 23, -64);
	printf("\e[35m%s\e[0m", hold);
	free(hold);

 	hold = ft_strnew(100);
	int a = 5;
	printf("\e[34mpointer: %p\n", &a);
	ft_snprintf(hold, 100, "pointer: %p\n", &a);
	printf("\e[35m%s\e[0m", hold);
	free(hold);

	hold = ft_strnew(100);
	printf("\e[34mhex: %x\n", 255);
	ft_snprintf(hold, 100, "hex: %x\n", 255);
	printf("\e[35m%s\e[0m", hold);
	free(hold);

	hold = ft_strnew(100);
	printf("\e[34mPercent: %%\n");
	ft_snprintf(hold, 100, "Percent: %%\n");
	printf("\e[35m%s\e[0m", hold);
	free(hold);

	return (0);
}
