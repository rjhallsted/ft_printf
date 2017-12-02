/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:19:26 by suvitiel          #+#    #+#             */
/*   Updated: 2017/12/01 16:21:56 by rhallste         ###   ########.fr       */
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

size_t					ft_vsnprintf_get_size_t(va_list ap)
{
	return (va_arg(ap, size_t));
}

ssize_t					ft_vsnprintf_get_ssize_t(va_list ap)
{
	return (va_arg(ap, ssize_t));
}
