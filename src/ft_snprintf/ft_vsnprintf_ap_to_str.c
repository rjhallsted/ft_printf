/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:18:25 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/01 16:32:34 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"
#include "../../inc/ft_printf.h"

#include <stdio.h>

static char *ap_to_str_str(va_list ap, int arg_type)
{
	char *(*func)(va_list);
	char *str;

	func = ft_vsnprintf_func_dispatch(arg_type);
	str = func(ap);
	return (ft_strdup(str));
}

static char *ap_to_str_sdec(va_list ap, int arg_type)
{
	int		(*func)(va_list);
	char	*str;

	func = ft_vsnprintf_func_dispatch(arg_type);
	str = ft_itoa(func(ap));
	return (str);
}

static char *ap_to_str_udec(va_list ap, int arg_type)
{
	unsigned int	(*func)(va_list);
	unsigned int	val;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	return (ft_uitoa(val));
}

static char *ap_to_str_char(va_list ap, int arg_type)
{
	int				(*func)(va_list);
	char			*str;
	
	str = ft_strnew(1);
	//char is to promotable to int, thus we use int below. Will need
	//to protect against things a bit.
	if (arg_type == TYPE_CHAR || arg_type == TYPE_UCHAR)
		arg_type = TYPE_INT;
	func = ft_vsnprintf_func_dispatch(arg_type);
	str[0] = (unsigned char)func(ap);
	return (str);
}

static char *ap_to_str_octal(va_list ap, int arg_type)
{
	unsigned int	(*func)(va_list);
	unsigned int	val;
	char			*str;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	str = ft_itoa_base(val, 8);
	return (str);
}

static char *ap_to_str_pointer(va_list ap, int arg_type)
{
	void *(*func)(va_list);
	void *ptr;
	char *addr;
	char *padded_addr;

	func = ft_vsnprintf_func_dispatch(arg_type);
	ptr = func(ap);
	if (ptr != NULL)
	{
		addr = ft_itoa_base((int)ptr, 16);
		padded_addr = ft_strjoin("0x7fff", addr);
		free(addr);
		return (padded_addr);
	}
	else
		return (ft_strdup("NULL"));
}

static char *ap_to_str_hex(va_list ap, int arg_type)
{
	unsigned int	(*func)(va_list);
	unsigned int	val;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	return (ft_itoa_base(val, 16));
}

static char *ap_to_str_percent(void)
{
	return (ft_strdup("%"));
}

static void *get_input_format_func(const char *f)
{
	if (*f == 'h' || *f == 'l' || *f == 'j' || *f == 'z')
		return (get_input_format_func(f + 1));
	if (*f == 's' || *f == 'S')
		return (&ap_to_str_str);
	else if (*f == 'p')
		return (&ap_to_str_pointer);
	else if (*f == 'd' || *f == 'D' || *f == 'i')
	 	return (&ap_to_str_sdec);
	else if (*f == 'o' || *f == 'O')
		return (&ap_to_str_octal);
	else if (*f == 'u' || *f == 'U')
	 	return (&ap_to_str_udec);
	else if (*f == 'c' || *f == 'C')
		return (*ap_to_str_char);
	else if (*f == 'x' || *f == 'X')
		return (&ap_to_str_hex);
	else if (*f == '%')
		return (&ap_to_str_percent);
	return (NULL);
}

static int get_conversion_type(const char *f)
{
	int next_type;
	if (*f == 'h')
	{
		if (*(f + 1) == 'h')
			return (TYPE_UCHAR);
		else
			return ((get_conversion_type(f + 1) == TYPE_UINT) ? TYPE_USH_INT : TYPE_SH_INT);
	}
	if (*f == 'l')
	{
		if (*(f + 1) == 'l')
			return ((get_conversion_type(f + 2) == TYPE_UINT) ? TYPE_ULL_INT : TYPE_LL_INT);
		else
		{
			next_type = get_conversion_type(f + 1);
			if (next_type == TYPE_UINT)
				return (TYPE_UL_INT);
			if (next_type == TYPE_INT)
				return (TYPE_L_INT);
			if (next_type == TYPE_CHAR)
				return (TYPE_WINT);
			if (next_type == TYPE_STR)
				return (TYPE_WCHAR);
		}
	}
	if (*f == 'j')
		return ((get_conversion_type(f + 1) == TYPE_UINT) ? TYPE_UINTMAX : TYPE_INTMAX);
	if (*f == 'z')
		return ((get_conversion_type(f + 1) == TYPE_UINT) ? TYPE_SIZET : TYPE_SSIZET);
	if (*f == 's' || *f == 'S')
		return (TYPE_STR);
	if (*f == 'p')
		return (TYPE_PTR);
	if (*f == 'd' || *f == 'D' || *f == 'i')
		return (TYPE_INT);
	if (*f == 'c' || *f == 'C')
		return (TYPE_CHAR);
	if (*f == 'o' || *f == 'O' || *f == 'u' || *f == 'U' || *f == 'x' || *f == 'X')
		return (TYPE_UINT);
	if (*f == '%')
		return (TYPE_INT);
	return (0);
}

static char *get_field(va_list ap, const char *format)
{
	int type;
	char *(*func)(va_list, int);

	type = get_conversion_type(format);
	func = get_input_format_func(format);
	return (func(ap, type));
}

int get_format_spec_len(const char *format)
{
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
