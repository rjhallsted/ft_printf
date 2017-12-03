/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_ap_to_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:32:04 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/02 16:25:44 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"
#include "../../inc/ft_printf.h"

static void *get_input_format_func(const char *f)
{
	if (*f == 'h' || *f == 'l' || *f == 'j' || *f == 'z')
		return (get_input_format_func(f + 1));
	if (*f == 's' || *f == 'S')
		return (&ft_vsnprintf_ap_to_str_str);
	else if (*f == 'p')
		return (&ft_vsnprintf_ap_to_str_ptr);
	else if (*f == 'd' || *f == 'D' || *f == 'i')
	 	return (&ft_vsnprintf_ap_to_str_sdec);
	else if (*f == 'o' || *f == 'O')
		return (&ft_vsnprintf_ap_to_str_octal);
	else if (*f == 'u' || *f == 'U')
	 	return (&ft_vsnprintf_ap_to_str_udec);
	else if (*f == 'c' || *f == 'C')
		return (&ft_vsnprintf_ap_to_str_char);
	else if (*f == 'x' || *f == 'X')
		return (&ft_vsnprintf_ap_to_str_hex);
	else if (*f == '%')
		return (&ft_vsnprintf_ap_to_str_percent);
	return (NULL);
}

static int conv_type_search(char *formats[20], const char *f)
{
	char spec[4];
	int i;

	ft_strncpy(spec, f, 3);
	spec[3] = '\0';
	i = 0;
	while (i <= TYPE_LL_INT)
	{
		if (ft_strstr(formats[i], spec))
			return (i);
		i++;
	}
	spec[2] = '\0';
	while (i <= TYPE_SSIZET)
	{
		if (ft_strstr(formats[i], spec))
			return (i);
		i++;
	}
	spec[1] = '\0';
	while (i <= TYPE_CHAR)
	{
		if (ft_strstr(formats[i], spec))
			return (i);
		i++;
	}
	return (0);
}

static int conv_type(const char *f)
{
	char *formats[20];

	formats[TYPE_ULL_INT] = "llo,llu,llx,llX";
	formats[TYPE_LL_INT] = "lld,lli";
	formats[TYPE_UCHAR] = "hh";
	formats[TYPE_USH_INT] = "ho,hu,hx,hX";
	formats[TYPE_SH_INT] = "hd,hi";
	formats[TYPE_UL_INT] = "lo,O,lu,U,lx,lX";
	formats[TYPE_L_INT] = "ld,D,li";
	formats[TYPE_WINT] = "lc,lC";
	formats[TYPE_WCHAR] = "ls,lS";
	formats[TYPE_UINTMAX] = "jo,ju,jx,jX";
	formats[TYPE_INTMAX] = "jd,ji";
	formats[TYPE_SIZET] = "zo,zu,zx,zX";
	formats[TYPE_SSIZET] = "zd,zi";
	formats[TYPE_STR] = "s,S";
	formats[TYPE_PTR] = "p";
	formats[TYPE_UINT] = "o,u,x,X";
	formats[TYPE_INT] = "d,i";
	formats[TYPE_CHAR] = "c,C";

	return (conv_type_search(formats, f));
}

static char *get_field(va_list ap, const char *format)
{
	int type;
	char *(*func)(va_list, int);

	type = conv_type(format);
	func = get_input_format_func(format);
	return (func(ap, type));
}

int get_format_spec_len(const char *format)
{
	//This will return an incorrect result for %hhh, %lji, %zz, etc. Need to fix
	if (*format == 'h' || *format == 'l' || *format == 'j' || *format == 'z')
		return (1 + get_format_spec_len(format + 1));
	else
		return (1);
}

int ft_vsnprintf_ap_to_str(char *str, va_list ap, const char *format)
{
	char	*field;

	//flags
	//field width
	//period then precision
	//length modifier
	//conversion
	field = get_field(ap, format);
	ft_strncat(str, field, ft_strlen(field));
	free(field);
	return (get_format_spec_len(format));
}
