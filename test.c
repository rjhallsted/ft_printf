/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:13:18 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/05 21:46:30 by rhallste         ###   ########.fr       */
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

	ft_bzero(expected, 1000);
	ft_bzero(expected, 1000);
	va_start(ap, format);
	vsnprintf(expected, 999, format, ap);
	va_end(ap);
	va_start(ap, format);
	ft_vsnprintf(actual, 999, format, ap);
	va_end(ap);
	printf("%-30s -> %d\n", format, ft_strcmp(expected, actual) == 0);
}

int main(void)
{
	run_test("Ints: %d, %i", 5, -12);
	run_test("Char: %c", 'a');
	run_test("Long: %ld, %D", (long)12351253312, (long)-123423523523);
	run_test("LLong: %lld, %lld", (long long)123124129184912849, (long long)-12412941928491);
	return (0);
}
