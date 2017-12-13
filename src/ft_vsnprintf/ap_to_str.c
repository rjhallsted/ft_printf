/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/13 10:27:15 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

#include <stdio.h>

static char *handle_flags(ft_format_t format, char *s)
{
	char	*flags;
	char	*new;

	flags = format.flags;
	if (ft_strchr(flags, ' ') && !ft_strchr(s, '-') && format.field_width > -1)
	{
		new = ft_strjoin(" ", s);
		free(s);
	}
	else
		new = s;
	if (ft_strchr(flags, '0') && !ft_strchr(flags, '-') && format.field_width > -1)
		ft_strreplace(new, ' ', '0');
	return (new);
}

//probably shouldn't free s here, but rather in it's original function, for clarity.
static char *handle_precision(ft_format_t format, char *s)
{
	char 	*precise;

	if (format.precision == -1)
		return (s);
	if (format.conversion == STR_T)
	{
		precise = ft_strsub(s, 0, format.precision);
		free(s);
		return (precise);
	}
	else if (format.precision - (int)ft_strlen(s) > 0)
	{
		precise = ft_padnumstr(s, format.precision - ft_strlen(s));
		free(s);
		return (precise);
	}
	return (s);
}

static char	*handle_field_width(ft_format_t format, char *s)
{
	char	*widened;
	char	*padding;
	int		len;
	int		right_side;
	
	len = ft_strlen(s);
	right_side = (format.field_width < 0);
	format.field_width *= (right_side) ? -1 : 1;
	if (format.field_width <= len)
		return (s);
	if (ft_strchr(format.flags, ' ') && !right_side)
		format.field_width--;
	padding = ft_xstring(' ', format.field_width - len);
	widened = (right_side) ? ft_strjoin(s, padding) : ft_strjoin(padding, s);
	free(s);
	free(padding);
	return (widened);
}

static char	*process_return(ft_format_t format, char *s)
{
	
	s = handle_precision(format, s);
	s = handle_field_width(format, s);
	s = handle_flags(format, s);
	return (s);
}

char	*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format)
{
	intmax_t		signed_int;
	char			*new;
	
	signed_int = va_arg(ap, intmax_t);
	if (format.conversion == CHAR_T)
	{
		new = ft_xstring((unsigned char)signed_int, 1);
		return (process_return(format, new));
	}
	if (format.len_mod == CHAR_MOD)
		signed_int = (char)signed_int;
	else if (format.len_mod == SHORT_MOD)
		signed_int = (short)signed_int;
	else if (format.len_mod == LONG_MOD)
		signed_int = (long)signed_int;
	else if (format.len_mod == LONGLONG_MOD)
		signed_int = (long long)signed_int;
	else if (format.len_mod == SIZET_MOD)
		signed_int = (size_t)signed_int;
	else if (format.len_mod == NONE_MOD)
		signed_int = (int)signed_int;
	return (process_return(format, ft_intmaxtoa(signed_int)));
}

char	*ft_vsnprintf_ap_uint_to_str(va_list ap, ft_format_t fmt)
{
	uintmax_t		unsigned_int;
	unsigned int	b;
	char			*new;

	unsigned_int = va_arg(ap, uintmax_t);
	if (fmt.conversion == CHAR_T)
	{
		new = ft_xstring((unsigned char)unsigned_int, 1);
		return (process_return(fmt, new));
	}
	if (fmt.len_mod == CHAR_MOD)
		unsigned_int = (unsigned char)unsigned_int;
	if (fmt.len_mod == SHORT_MOD)
		unsigned_int = (unsigned short)unsigned_int;
	else if (fmt.len_mod == LONG_MOD)
		unsigned_int = (unsigned long)unsigned_int;
	else if (fmt.len_mod == LONGLONG_MOD)
		unsigned_int = (unsigned long long)unsigned_int;
	else if (fmt.len_mod == SIZET_MOD)
		unsigned_int = (size_t)unsigned_int;
	else if (fmt.len_mod == NONE_MOD)
		unsigned_int = (unsigned int)unsigned_int;
	b = (fmt.disp_mod == OCT_DISP) ? 8 : 10;
	b = (fmt.disp_mod == HEX_DISP || fmt.disp_mod == HEX_UP_DISP) ? 16 : b;
	if (fmt.disp_mod == HEX_UP_DISP)
		new = ft_strtoup(ft_uintmaxtoa_base(unsigned_int, b));
	else
		new = ft_uintmaxtoa_base(unsigned_int, b);
	return (process_return(fmt, new));
}

char	*ft_vsnprintf_ap_str_to_str(va_list ap, ft_format_t format)
{
	int		i;
	size_t	len;
	char	*new;
	wchar_t	*wide;
	
	if (format.len_mod == LONG_MOD)
	{
		wide = va_arg(ap, wchar_t *);
		len = ft_wstrlen(wide);
		new = ft_strnew(len);
		i = -1;
		while (++i < (int)len)
			new[i] = (char)wide[i];
		return (process_return(format, new));
	}
	else
	{
		new = ft_strdup(va_arg(ap, char *));
		return (process_return(format, new));
	}
}

char	*ft_vsnprintf_ap_ptr_to_str(va_list ap, ft_format_t format)
{
	void *ptr;
	char *hex;
	char *new;
	
	ptr = va_arg(ap, void *);
	hex = ft_uintmaxtoa_base((unsigned long)ptr, 16);
	new = ft_strjoin("0x", hex);
	free(hex);
	return (process_return(format, new));
}
