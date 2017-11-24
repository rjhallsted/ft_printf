/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:29:05 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/23 20:20:32 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

#include <stdio.h>

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list ap;
	size_t	str_pos;
	char	*field;

	va_start(ap, format);
	str_pos = 0;
	while (*format && str_pos < size - 1)
	{
		if (*format == '%')
		{
			format++;
			//flags
			//field width
			//period then precision
			//length modifier
			//conversion
			field = ap_to_str(ap, format);
			ft_strncat(str, field, ft_strlen(field));
			str_pos += ft_strlen(field) - 1;
			free(field);
		}
		else
			str[str_pos] = *format;
		format++;
		str_pos++;
	}
	va_end(ap);
	return str_pos;
}
