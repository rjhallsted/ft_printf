/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:18:25 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/23 23:00:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static char *ap_to_str_str(va_list ap)
{
	return (ft_strdup(va_arg(ap, char *)));
}

static char *ap_to_str_sdec(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));
}

static char *ap_to_str_udec(va_list ap)
{
	return (ft_uitoa(va_arg(ap, unsigned int)));
}

static char *ap_to_str_char(va_list ap)
{
	char *str;
	
	str = ft_strnew(1);
	//char is to promotable to int, thus we use int below. Will need
	//to protect agains things a bit.
	str[0] = (unsigned char)va_arg(ap, int);
	return (str);
}

static char *ap_to_str_octal(va_list ap)
{
	return (ft_itoa_base(va_arg(ap, unsigned int), 8));
}

static char *ap_to_str_pointer(va_list ap)
{
	void *ptr;
	char *addr;
	char *padding;
	char *padded_addr;

	ptr = va_arg(ap, void *);
	if (ptr != NULL)
	{
		addr = ft_itoa_base((int)ptr, 16);
		padding = "0x7fff";
		padded_addr = ft_strjoin(padding, addr);
		free(addr);
		return (padded_addr);
	}
	else
		return (ft_strdup("NULL"));
}

static char *ap_to_str_hex(va_list ap)
{
	return (ft_itoa_base(va_arg(ap, unsigned int), 16));
}

char *ap_to_str(va_list ap, const char *format)
{
	//determine expected type.
	//call va_arg appropriately
	//call appropriate conversion to string function
	//return string
	if (*format == 's' || *format == 'S')
		return (ap_to_str_str(ap));
	else if (*format == 'p')
		return (ap_to_str_pointer(ap));
	else if (*format == 'd' || *format == 'D' || *format == 'i')
	 	return (ap_to_str_sdec(ap));
	else if (*format == 'o' || *format == 'O')
		return (ap_to_str_octal(ap));
	else if (*format == 'u' || *format == 'U')
	 	return (ap_to_str_udec(ap));
	else if (*format == 'c' || *format == 'C')
		return (ap_to_str_char(ap));
	else if (*format == 'x' || *format == 'X')
		return (ap_to_str_hex(ap));
	else if (*format == '%')
		return (ft_strdup("%"));
	return (ft_strnew(0));
}
