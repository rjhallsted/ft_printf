/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/09 14:03:51 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

//probably shouldn't free s here, but rather in it's original function, for clarity.
static char *handle_precision(ft_format_t format, char *s)
{
	char *precise;
	char *tmp;
	
	if (format.precision == -1)
		return (s);
	if (format.conversion == STR_T)
	{
		precise = ft_strsub(s, 0, format.precision);
		free(s);
		return (precise);
	}
	else
	{
		tmp = ft_xstring('0', format.precision - ft_strlen(s));
		precise = ft_strjoin(tmp, s);
		free(tmp);
		free(s);
		return (precise);
	}
}

char	*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format)
{
	intmax_t		signed_int;
	
	signed_int = va_arg(ap, intmax_t);
	if (format.conversion == CHAR_T)
		return (ft_xstring((unsigned char)signed_int, 1));
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
	return (handle_precision(format, ft_intmaxtoa(signed_int)));
}

char	*ft_vsnprintf_ap_uint_to_str(va_list ap, ft_format_t fmt)
{
	uintmax_t		unsigned_int;
	unsigned int	b;
	char			*new;

	unsigned_int = va_arg(ap, uintmax_t);
	if (fmt.conversion == CHAR_T)
		return (ft_xstring((unsigned char)unsigned_int, 1));
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
	return (handle_precision(fmt, new));
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
		return (handle_precision(format, new));
	}
	else
	{
		new = ft_strdup(va_arg(ap, char *));
		return (handle_precision(format, new));
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
	return (new);
}
