/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:14:36 by suvitiel          #+#    #+#             */
/*   Updated: 2017/11/25 16:40:38 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../../inc/ft_printf.h"

char			ft_vsnprintf_get_char(va_list ap)
{
	return ((char)va_arg(ap, int));
}

unsigned char	ft_vsnprintf_get_uchar(va_list ap)
{
	return ((unsigned char)va_arg(ap, unsigned int));
}

char			*ft_vsnprintf_get_str(va_list ap)
{
	return (va_arg(ap, char *));
}

wchar_t			ft_vsnprintf_get_wchar(va_list ap)
{
	return (va_arg(ap, wchar_t));
}

void			*ft_vsnprintf_get_ptr(va_list ap)
{
	return (va_arg(ap, void *));
}
