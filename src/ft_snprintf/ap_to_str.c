/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:18:25 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 14:22:42 by rhallste         ###   ########.fr       */
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

char *ap_to_str(va_list ap, const char *format)
{
	//determine expected type.
	//call va_arg appropriately
	//call appropriate conversion to string function
	//return string
	if (*format == 's' || *format == 'S')
		return (ap_to_str_str(ap));
	/* else if (*format == 'p') */
	/* 	return(ap_to_str_pointer(ap)); */
	else if (*format == 'd' || *format == 'D' || *format == 'i')
	 	return(ap_to_str_sdec(ap));
	/* else if (*format == 'o' || *format == 'O') */
	/* 	return(ap_to_str_octal(ap, 8)); */
	else if (*format == 'u' || *format == 'U')
	 	return(ap_to_str_udec(ap));
	/* else if (*format == 'c' || *format == 'C') */
	/* 	return(ap_to_str_char(ap)); */
	return NULL;
}
