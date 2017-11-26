/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/25 15:34:55 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

#define LIB_COLOR "\e[34m"
#define FT_COLOR "\e[35m"
#define NORM_COLOR "\e[0m"

void print_lib(char *format, va_list ap)
{
	printf("%s", LIB_COLOR);
	vprintf(format, ap);
	printf(NORM_COLOR);
}

void print_ft(char *format, va_list ap)
{
	char *hold;
	
	hold = ft_strnew(100);
	ft_vsnprintf(hold, 100, format, ap);
	printf("%s%s%s", FT_COLOR, hold, NORM_COLOR);
	free(hold);
}

void run_test(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	print_lib(format, ap);
	va_end(ap);
	va_start(ap, format);
	print_ft(format, ap);
	va_end(ap);
}


int main(void)
{
	int pt = 12;
	char *test = ft_strnew(13);
	
	run_test("string: %s\n", "this");
	run_test("Signed dec: %d, %D, %i\n", 2, 2, 2);
	run_test("Unsigned dec: %u, %u\n", 3, 13244214);
	run_test("char %c, %c\n", 'a', '\200');
	run_test("Octal: %o, %O, %o\n", 1, 23, -64);
	int a = 5;
	run_test("pointer: %p, %p, %p\n", &a, &pt, &test);
	run_test("hex: %x, %X\n", 255, 36);
	run_test("Percent: %%\n");

	run_test("Char->Int: %hhd\n", 'a');
	
	free(test);
	return (0);
}
