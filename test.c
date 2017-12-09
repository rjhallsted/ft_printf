/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:13:18 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/09 12:53:48 by rhallste         ###   ########.fr       */
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
		printf("\t%s%s%s\n", color, expected, "\e[0;m");
		printf("\t%s%s%s\n", color, actual, "\e[0;m");
	}
}

int main(void)
{
	wchar_t	wide_chars[4] = {0x00f5, 0x00f6, 0x00f7, L'\0'};
	
	run_test("No spec:");
	run_test("Percent: %%");

	run_test("Strings: %s, %s", "running really", "successfully damn fast");
	run_test("Wide chars: %ls", wide_chars);

	run_test("Ints: %d, %i", 5, -12);
	run_test("Char: %c", 'a');
	run_test("Long: %ld, %D", (long)12351253312, (long)-123423523523);
	run_test("LLong: %lld, %lld", (long long)123124129184912849, (long long)-12412941928491);
	run_test("Size_t: %zd, %zu, %zd, %zu", 12, (ssize_t)-12, (ssize_t)-12, 12);
	run_test("IntMax: %jd, %ji", 1234214142141421, -12312414);
	run_test("CharMod: %hhd", 18314);
	run_test("ShortInt: %hd", -12423);
	run_test("WideInt: %lc, %C", (wint_t)123, (wint_t)124141);
	
	run_test("Bases: %x, %X,  %o", 1235, 1235, 12414);

	run_test("Unsigned Ints: %u, %x, %o", 5, 12, 123);
	run_test("ULong: %lu, %U, %O", 12351253312, 123423523523);
	run_test("ULLong: %llu, %llu", 123124129184912849, 12412941928491);
	run_test("UIntMax: %ju, %jo", 1234214142141421, 12312414);
	run_test("UCharMod: %hhu", 18314);
	run_test("ShortUint: %hu", 12341);

	return (0);
}
