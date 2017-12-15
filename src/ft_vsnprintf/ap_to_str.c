/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/14 23:45:45 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static char	*ap_int_to_str(va_list ap, ft_format_t format, char *s)
{
	intmax_t		signed_int;
	char			*tmp;
	
	signed_int = va_arg(ap, intmax_t);
	if (format.conversion == CHAR_T)
	{
		*s = (unsigned char)signed_int;
		*(s + 1) = '\0';
		format.is_nullchar = (*s == '\0');
		return (ft_vsnprintf_process_return(format, s));
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
	tmp =  ft_intmaxtoa(signed_int);
	ft_strcpy(s,tmp);
	free(tmp);
	return (ft_vsnprintf_process_return(format, s));
}

static char	*ap_uint_to_str(va_list ap, ft_format_t fmt, char *s)
{
	uintmax_t		unsigned_int;
	unsigned int	b;
	char			*new;

	unsigned_int = va_arg(ap, uintmax_t);
	if (fmt.conversion == CHAR_T)
	{
		new = ft_xstring((unsigned char)unsigned_int, 1);
		ft_strcpy(s, new);
		free(new);
		return (ft_vsnprintf_process_return(fmt, s));
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
	{
		new = ft_uintmaxtoa_base(unsigned_int, b);
		ft_strtoup(new);
	}
	else
		new = ft_uintmaxtoa_base(unsigned_int, b);
	ft_strcpy(s, new);
	free(new);
	return (ft_vsnprintf_process_return(fmt, s));
}

static char	*ap_str_to_str(va_list ap, ft_format_t format, char *s)
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
		ft_strcpy(s, new);
		free(new);
		return (ft_vsnprintf_process_return(format, s));
	}
	else
	{
		new = va_arg(ap, char *);
		new = (new) ? new : "(null)";
		ft_strcpy(s, new);
		return (ft_vsnprintf_process_return(format, s));
	}
}

static char	*ap_ptr_to_str(va_list ap, ft_format_t format, char *s)
{
	void *ptr;
	char *tmp;

	ptr = va_arg(ap, void *);
	tmp = ft_uintmaxtoa_base((unsigned long)ptr, 16);
	ft_strcpy(s, "0x");
	ft_strcat(s, tmp);
	free(tmp);
	return (ft_vsnprintf_process_return(format, s));
}

char			*ft_vsnprintf_ap_to_str(va_list ap, ft_format_t format, char *s)
{
	if (format.conversion == INT_T || format.conversion == CHAR_T)
		return (ap_int_to_str(ap, format, s));
	if (format.conversion == UINT_T)
		return (ap_uint_to_str(ap, format, s));
	if (format.conversion == STR_T)
		return (ap_str_to_str(ap, format, s));
	if (format.conversion == PTR_T)
		return (ap_ptr_to_str(ap, format, s));
	return (NULL);
}
