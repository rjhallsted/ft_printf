/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:29:05 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 11:03:38 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list ap;
	size_t	str_pos;

	va_start(ap, format);
	str_pos = 0;
	while (*format && str_pos < size - 1)
	{
		if (*format == '%')
		{
			format++;
			va_arg(ap, int);
			//do things
		}
		else
			str[str_pos] = *format;
		format++;
	}
	va_end(ap);
	return str_pos;
}
