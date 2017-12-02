/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:34:03 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/02 12:50:30 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../../inc/libft.h"
#include "../../../inc/ft_printf.h"

char *ft_vsnprintf_ap_to_str_str(va_list ap, int arg_type)
{
	char *(*func)(va_list);
	char *str;

	func = ft_vsnprintf_func_dispatch(arg_type);
	str = func(ap);
	return (ft_strdup(str));
}

char *ft_vsnprintf_ap_to_str_char(va_list ap, int arg_type)
{
	int				(*func)(va_list);
	char			*str;
	
	str = ft_strnew(1);
	if (arg_type == TYPE_CHAR)
		arg_type = TYPE_INT;
	if (arg_type == TYPE_UCHAR)
		arg_type = TYPE_UINT;
	func = ft_vsnprintf_func_dispatch(arg_type);
	str[0] = (unsigned char)func(ap);
	return (str);
}

char *ft_vsnprintf_ap_to_str_ptr(va_list ap, int arg_type)
{
	void *(*func)(va_list);
	void *ptr;
	char *addr;
	char *padded_addr;

	func = ft_vsnprintf_func_dispatch(arg_type);
	ptr = func(ap);
	if (ptr != NULL)
	{
		addr = ft_itoa_base((int)ptr, 16);
		padded_addr = ft_strjoin("0x7fff", addr);
		free(addr);
		return (padded_addr);
	}
	else
		return (ft_strdup("NULL"));
}

char *ft_vsnprintf_ap_to_str_percent(void)
{
	return (ft_strdup("%"));
}

