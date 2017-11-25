/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:18:25 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/25 00:41:55 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"
#include "../../inc/ft_printf.h"

static void *get_arg(va_list ap, int type)
{
	int				*int_val;
	unsigned int	*uint_val;
	
	if (type == TYPE_INT)
	{
		int_val = malloc(sizeof(int));
		*int_val = va_arg(ap, int);
		return ((void *)int_val);
	}
	else if (type == TYPE_UINT)
	{
		uint_val = malloc(sizeof(unsigned int));
		*uint_val = va_arg(ap, unsigned int);
		return ((void *)uint_val);
	}
	else if (type == TYPE_STR)
		return ((va_arg(ap, char *)));
	else if (type == TYPE_PTR)
		return ((va_arg(ap, void *)));
	else
		return (NULL);
}

static char *ap_to_str_str(va_list ap, int arg_type)
{
	char *str;

	str = (char *)get_arg(ap, arg_type);
	return (ft_strdup(str));
}

static char *ap_to_str_sdec(va_list ap, int arg_type)
{
	int		*ptr;
	char	*str;
	
	ptr = (int *)get_arg(ap, arg_type);
	str = ft_itoa(*ptr);
	free(ptr);
	return (str);
}

static char *ap_to_str_udec(va_list ap, int arg_type)
{
	unsigned int	*ptr;
	char			*str;

	ptr = (unsigned int *)get_arg(ap, arg_type);
	str = ft_uitoa(*ptr);
	free(ptr);
	return (str);
}

static char *ap_to_str_char(va_list ap, int arg_type)
{
	unsigned char	*ptr;
	char			*str;
	
	str = ft_strnew(1);
	//char is to promotable to int, thus we use int below. Will need
	//to protect against things a bit.
	ptr = (unsigned char *)get_arg(ap, arg_type);
	str[0] = *ptr;
	free(ptr);
	return (str);
}

static char *ap_to_str_octal(va_list ap, int arg_type)
{
	unsigned int	*ptr;
	char			*str;

	ptr = (unsigned int *)get_arg(ap, arg_type);
	str = ft_itoa_base(*ptr, 8);
	free(ptr);
	return (str);
}

static char *ap_to_str_pointer(va_list ap, int arg_type)
{
	void *ptr;
	char *addr;
	char *padding;
	char *padded_addr;

	ptr = get_arg(ap, arg_type);
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

static char *ap_to_str_hex(va_list ap, int arg_type)
{
	unsigned int	*ptr;
	char			*str;

	ptr = (unsigned int *)get_arg(ap, arg_type);
	str = ft_itoa_base(*ptr, 16);
	free(ptr);
	return (str);
}

static char *ap_to_str_percent(void)
{
	return (ft_strdup("%"));
}

static void *get_input_format_func(char c)
{
	if (c == 's' || c == 'S')
		return (&ap_to_str_str);
	else if (c == 'p')
		return (&ap_to_str_pointer);
	else if (c == 'd' || c == 'D' || c == 'i')
	 	return (&ap_to_str_sdec);
	else if (c == 'o' || c == 'O')
		return (&ap_to_str_octal);
	else if (c == 'u' || c == 'U')
	 	return (&ap_to_str_udec);
	else if (c == 'c' || c == 'C')
		return (*ap_to_str_char);
	else if (c == 'x' || c == 'X')
		return (&ap_to_str_hex);
	else if (c == '%')
		return (&ap_to_str_percent);
	return (NULL);
}

static int get_conversion_type(char c)
{
	if (c == 's' || c == 'S')
		return (TYPE_STR);
	if (c == 'p')
		return (TYPE_PTR);
	if (c == 'd' || c == 'D' || c == 'i'
		|| c == 'c' || c == 'C')
		return (TYPE_INT);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		return (TYPE_UINT);
	if (c == '%')
		return (TYPE_INT);
	return (0);
}

static char *get_field(va_list ap, const char *format)
{
	int type;
	char *(*func)(va_list, int);

	type = get_conversion_type(*format);
	func = get_input_format_func(*format);
	return (func(ap, type));
}

int get_format_spec_len(const char *format)
{
	format++;
	return (1);
}

int ap_to_str(char *str, va_list ap, const char *format)
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
