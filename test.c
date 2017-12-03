/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/02 16:24:11 by rhallste         ###   ########.fr       */
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
	char *test = ft_strnew(13);

	run_test("Char:\t%c, %C\n", 'a', '\100');
	run_test("Int:\t%d, %i\n", 12, -31);
	run_test("Uint:\t%u\n", -12);
	run_test("Ptr:\t%p\n", &test);
	run_test("Str:\t%s, %S\n", "red", "blue");
	run_test("Ssize_t:\t%zd, %zi\n", 12, -12);
	run_test("Size_t:\t%zo, %zu, %zx, %zX\n", 12, 32, 32, 49);
	run_test("IntMax:\t%jd, %ji\n", 12334153213541, -12341341234143);
	run_test("UintMax:\t%jo, %ju, %jx, %jX\n", 123, 21451, 1234, 1342351511);
	//wchar
	//wint
	run_test("Lint:\t%ld, %D, %li\n", 123, 124125, -123);
	run_test("ULint:\t%lo, %O, %lu, %U, %lx, %lX\n", 132, 123412415, 124151553, 15135235, 12414, 1315151255);
	run_test("Shint:\t%hd, %hi\n", 123, -124);
	run_test("UShint:\t%ho, %hu, %hx, %hX\n", 124124, 1241, 124, 1234);
	run_test("Uchar:\t%hh\n", 'a');
	run_test("LLint:\t%lld, %lli\n", 1234567, -123425325);
	run_test("ULLint:\t%llo, %llu, %llx, %llX\n", 12, 123412342134, 1341243214, 152353151313);
	
	free(test);
	return (0);
}
