/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/04 14:20:51 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/ft_printf.h"

char	*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format)
{
	long long int signed_int;
	
	if (format.len_mod == CHAR_MOD || format.len_mod == SHORT_MOD
		|| format.len_mod == NONE_MOD)
	{
		signed_int = va_arg(ap, int);
		if (format.len_mod == CHAR_MOD)
			return (ft_xstring((unsigned char)signed int, 1));
		if (format.len == SHORT_MOD)
			signed_int = (short)signed_int;
		return (ft_itoa(signed_int));
	}
	if (format.len_mod == LONG_MOD)

}
