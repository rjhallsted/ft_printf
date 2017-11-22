/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:29:05 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/21 21:35:06 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list *ap;
	int str_pos;

	va_start(ap, format);
	str_pos = 0;
	while (*format && str_pos < size - 1;)
	{
		if (*format == '%')
		{
			format++;
			//do things
		}
		else
			str[str_pos] = *format;
		format++;
	}
	return str_pos;
}
