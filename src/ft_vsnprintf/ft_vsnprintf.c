/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:36:32 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/04 11:38:27 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

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
			format += ft_vsnprintf_ap_to_str(str, ap, format);
			str_pos = ft_strlen(str);
		}
		else
			str[str_pos++] = *format++;
	}
	return str_pos;
}
