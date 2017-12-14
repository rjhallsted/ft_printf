/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:13:18 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/13 21:23:00 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "inc/libft.h"

void run_test(const char *format, ...)
{
	va_list ap;
	char	expected[1000];
	char	actual[1000];
	int		result;
	char	*color;

	ft_bzero(expected, 1000);
	ft_bzero(expected, 1000);
	va_start(ap, format);
	vsnprintf(expected, 999, format, ap);
	va_end(ap);
	va_start(ap, format);
	ft_vsnprintf(actual, 999, format, ap);
	va_end(ap);
	result = (ft_strcmp(expected, actual) == 0);
	color = (result) ? "\e[0;32m" : "\e[0;31m";
	printf("%s%-30s -> %d%s\n", color, format, result, "\e[0;m");
	if (!result)
	{
		printf("\t%s|%s|%s\n", color, expected, "\e[0;m");
		printf("\t%s|%s|%s\n", color, actual, "\e[0;m");
	}
}

int main(void)
{
	wchar_t	wide_chars[4] = {0x00f5, 0x00f6, 0x00f7, L'\0'};
	char *nil;
	nil = NULL;
	
	printf("NULL c:%4c\n", '\0');
	ft_printf("ftNULL c:%4c\n", '\0');
	
	run_test("No spec:");
	run_test("Percent: %%");

	run_test("Strings: %.s, % -25s, %s", "running really", "successfully damn fast", NULL);
	run_test("Wide chars: %ls", wide_chars);

	run_test("Ints: %.d, % 5.4i", 5, -12);
	run_test("Char: %.c", 'a');
	run_test("Long: %.-3ld, %D", (long)12351253312, (long)-123423523523);
	run_test("LLong: %lld, %lld", (long long)123124129184912849, (long long)-12412941928491);
	run_test("Size_t: %zd, %zu, %zd, %zu", 12, (ssize_t)-12, (ssize_t)-12, 12);
	run_test("IntMax: %jd, %ji", 1234214142141421, -12312414);
	run_test("CharMod: %hhd", 18314);
	run_test("ShortInt: % 4.5hd", 42);
	run_test("WideInt: %lc, %3C", (wint_t)123, (wint_t)124);
	
	run_test("Bases: %x, %X,  %12o", 1235, 1235, 12414);

	run_test("Unsigned Ints: %u, %x, %o", 5, 12, 123);
	run_test("ULong: %lu, %U, %O", 12351253312, 123423523523);
	run_test("ULLong: %llu, %llu", 123124129184912849, 12412941928491);
	run_test("UIntMax: %ju, %jo", 1234214142141421, 12312414);
	run_test("UCharMod: %hhu", 18314);
	run_test("ShortUint: %hu", 12341);

	run_test("Pointer: %p", &wide_chars);

	ft_printf("%s\n", "actual printf test");

	run_test("4i 42: %4i", 42);
	run_test("04i 42: %04i", 42); 
	run_test("o INT_MAX: %o,", INT_MAX);
	run_test("#o INT_MIN: %#o", INT_MIN);
	run_test("o INT_MIN: %o", INT_MIN);
	run_test("#X INT_MIN: %#X", INT_MIN);
	run_test("+i 42: %+i", 42);
	run_test("Null c: %c", '\0');
	printf("real:%c\n", '\0');
	ft_printf("ft :%c\n", '\0');
	return (0);
}
