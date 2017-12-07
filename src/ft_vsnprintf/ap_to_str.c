/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 17:41:00 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

char	*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format)
{
	intmax_t signed_int;

	signed_int = va_arg(ap, intmax_t);
	if (format.len_mod == CHAR_MOD || format.conversion == CHAR_T)
		return (ft_xstring((unsigned char)signed_int, 1));
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
	unsigned long long unsigned_int;

	unsigned_int = va_arg(ap, unsigned long long);
	if (format.len_mod == CHAR_MOD || format.conversion == CHAR_T)
		return (ft_xstring((unsigned char)unsigned_int, 1));
	if (format.len_mod == SHORT_MOD)
		unsigned_int = (unsigned short)unsigned_int;
	else if (format.len_mod == LONG_MOD)
		unsigned_int = (unsigned long)unsigned_int;
	else if (format.len_mod == SIZET_MOD)
		unsigned_int = (size_t)unsigned_int;
	else if (format.len_mod == NONE_MOD)
		unsigned_int = (unsigned int)unsigned_int;
	return (ft_ulltoa(unsigned_int));		
}

char	*ft_vsnprintf_ap_ptr_to_str(va_list ap, ft_format_t format)
{
	return (ft_strdup(""));
}
