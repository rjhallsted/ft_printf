/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:29:05 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/25 00:47:07 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

#include <stdio.h>
	
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	size_t	str_pos;
	
	ft_bzero(str, size);
	str_pos = 0;
	while (*format && str_pos < size - 1)
	{
		if (*format == '%')
		{
			format++;
			format += ap_to_str(str, ap, format);
			str_pos = ft_strlen(str);
		}
		else
			str[str_pos++] = *format++;
	}
	return str_pos;
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	size_t	print_len;

	va_start(ap, format);
	print_len = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (print_len);
}
