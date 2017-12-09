/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/08 19:18:41 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

char	*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format)
{
	intmax_t		signed_int;
	
	signed_int = va_arg(ap, intmax_t);
	if (format.conversion == CHAR_T)
		return (ft_xstring((unsigned char)signed_int, 1));
	if (format.len_mod == CHAR_MOD)
		signed_int = (char)signed_int;
	if (format.len_mod == SHORT_MOD)
		signed_int = (short)signed_int;
	else if (format.len_mod == LONG_MOD)
		signed_int = (long)signed_int;
	else if (format.len_mod == LONGLONG_MOD)
		signed_int = (long long)signed_int;
	else if (format.len_mod == SIZET_MOD)
		signed_int = (size_t)signed_int;
	else if (format.len_mod == NONE_MOD)
		signed_int = (int)signed_int;
	return (ft_intmaxtoa(signed_int));
}

char	*ft_vsnprintf_ap_uint_to_str(va_list ap, ft_format_t format)
{
	uintmax_t		unsigned_int;
	unsigned int	base;

	unsigned_int = va_arg(ap, uintmax_t);
	if (format.conversion == CHAR_T)
		return (ft_xstring((unsigned char)unsigned_int, 1));
	if (format.len_mod == CHAR_MOD)
		unsigned_int = (unsigned char)unsigned_int;
	if (format.len_mod == SHORT_MOD)
		unsigned_int = (unsigned short)unsigned_int;
	else if (format.len_mod == LONG_MOD)
		unsigned_int = (unsigned long)unsigned_int;
	else if (format.len_mod == LONGLONG_MOD)
		unsigned_int = (unsigned long long)unsigned_int;
	else if (format.len_mod == SIZET_MOD)
		unsigned_int = (size_t)unsigned_int;
	else if (format.len_mod == NONE_MOD)
		unsigned_int = (unsigned int)unsigned_int;
	base = (format.disp_mod == OCT_DISP) ? 8 : 10;
	base = (format.disp_mod == HEX_DISP) ? 16 : base;
	return (ft_uintmaxtoa_base(unsigned_int, base));		
}

char	*ft_vsnprintf_ap_str_to_str(va_list ap, ft_format_t format)
{
	if (format.len_mod == LONG_MOD)
		return (ft_wcrtostr(va_arg(ap, wchar_t *)));
	else
		return (ft_strdup(va_arg(ap, char *)));
}

char	*ft_vsnprintf_ap_ptr_to_str(va_list ap, ft_format_t format)
{
	return (ft_strdup(""));
}
