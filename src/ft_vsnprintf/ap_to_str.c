/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/05 21:37:52 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

char	*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format)
{
	long long int signed_int;

	signed_int = va_arg(ap, long long int);
	if (format.len_mod == CHAR_MOD)
		return (ft_xstring((unsigned char)signed_int, 1));
	if (format.len_mod == SHORT_MOD)
		signed_int = (short)signed_int;
	else if (format.len_mod == LONG_MOD)
		signed_int = (long)signed_int;
	else if (format.len_mod == NONE_MOD)
		signed_int = (int)signed_int;
	return (ft_lltoa(signed_int));	
}

char	*ft_vsnprintf_ap_uint_to_str(va_list ap, ft_format_t format)
{
	return (ft_strdup(""));
}

char	*ft_vsnprintf_ap_ptr_to_str(va_list ap, ft_format_t format)
{
	return (ft_strdup(""));
}
