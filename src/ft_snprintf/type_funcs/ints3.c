/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:19:26 by suvitiel          #+#    #+#             */
/*   Updated: 2017/11/25 16:43:06 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../../inc/ft_printf.h"

wint_t					ft_vsnprintf_get_wint(va_list ap)
{
	return (va_arg(ap, wint_t));
}

intmax_t				ft_vsnprintf_get_intmax(va_list ap)
{
	return (va_arg(ap, intmax_t));
}

uintmax_t				ft_vsnprintf_get_uintmax(va_list ap)
{
	return (va_arg(ap, uintmax_t));
}

size_t					ft_vsnprintf_get_sizet(va_list ap)
{
	return (va_arg(ap, size_t));
}

ssize_t					ft_vsnprintf_get_ssizet(va_list ap)
{
	return (va_arg(ap, ssize_t));
}
