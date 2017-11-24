/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/23 23:25:45 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

#define LIB_COLOR "\e[34m"
#define FT_COLOR "\e[35m"
#define NORM_COLOR "\e[0m"

void print_color(char *color, char *format, va_list ap)
{
	printf("%s", color);
	vprintf(format, ap);
	printf(NORM_COLOR);
}

void print_lib(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	print_color(LIB_COLOR, format, ap);
	va_end(ap);
}

void print_ft(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	print_color(FT_COLOR, format, ap);
	va_end(ap);
}



int main(void)
{
	int pt = 12;
//	char *test = "test string";
	char *hold;
	hold = ft_strnew(100);
	print_lib("string: %s\n", "this");
	ft_snprintf(hold, 100, "string: %s\n", "this");
	print_ft("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	print_lib("Signed dec: %d, %D, %i\n", 2, 2, 2);
	ft_snprintf(hold, 100, "Signed dec: %d, %D, %i\n", 2, 2, 2);
	print_ft("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	print_lib("Unsigned dec: %u, %u\n", 3, 13244214);
	ft_snprintf(hold, 100, "Unsigned dec: %u, %u\n", 3, 13244214);
	print_ft("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	print_lib("char: %c, %c\n", 'a', '\200'); //libc printf doesn't support capital-C
	ft_snprintf(hold, 100, "char: %c, %C\n", 'a', '\200');
	print_ft("%s", hold);
	free(hold);

 	hold = ft_strnew(100);
	print_lib("Octal: %o, %O, %o\n", 1, 23, -64);
	ft_snprintf(hold, 100, "Octal: %o, %O, %o\n", 1, 23, -64);
	print_ft("%s", hold);
	free(hold);

 	hold = ft_strnew(100);
	int a = 5;
	print_lib("pointer: %p, %p, %p\n", &a, &pt, &hold);
	ft_snprintf(hold, 100, "pointer: %p, %p, %p\n", &a, &pt, &hold);
	print_ft("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	print_lib("hex: %x, %X\n", 255, 36);
	ft_snprintf(hold, 100, "hex: %x, %X\n", 255, 36);
	print_ft("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	print_lib("Percent: %%\n");
	ft_snprintf(hold, 100, "Percent: %%\n");
	print_ft("%s", hold);
	free(hold);

	return (0);
}
