/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:33:32 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/02 12:50:07 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../../inc/libft.h"
#include "../../../inc/ft_printf.h"

char *ft_vsnprintf_ap_to_str_sdec(va_list ap, int arg_type)
{
	int		(*func)(va_list);
	int		val;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	return (ft_itoa(val));
}

char *ft_vsnprintf_ap_to_str_udec(va_list ap, int arg_type)
{
	unsigned int	(*func)(va_list);
	unsigned int	val;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	return (ft_uitoa(val));
}

char *ft_vsnprintf_ap_to_str_octal(va_list ap, int arg_type)
{
	unsigned int	(*func)(va_list);
	unsigned int	val;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	return (ft_itoa_base(val, 8));
}

char *ft_vsnprintf_ap_to_str_hex(va_list ap, int arg_type)
{
	unsigned int	(*func)(va_list);
	unsigned int	val;

	func = ft_vsnprintf_func_dispatch(arg_type);
	val = func(ap);
	return (ft_itoa_base(val, 16));
}
