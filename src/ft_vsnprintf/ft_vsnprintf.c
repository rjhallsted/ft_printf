/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:36:32 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 11:31:54 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

#include <stdio.h>

static ft_format_t	get_format_struct(const char *format_str)
{
	ft_format_t format;

	if (!(ft_vsnprintf_check_shorthand(format_str, &format)))
	{
		format.len_mod = ft_vsnprintf_get_len_mod(format_str);
		if (format.len_mod == CHAR_MOD || format.len_mod == LONGLONG_MOD)
			format_str += 2;
		else if (format.len_mod != NONE_MOD)
			format_str++;
		else
			format.conversion = ft_vsnprintf_get_conversion(format_str);
	}
	return (format);
}

static char			*ap_to_str(va_list ap, ft_format_t format)
{
	if (format.conversion == INT_T || format.conversion == CHAR_T)
		return (ft_vsnprintf_ap_int_to_str(ap, format));
	if (format.conversion == UINT_T)
		return (ft_vsnprintf_ap_uint_to_str(ap, format));
	if (format.conversion == STR_T)
		return (ft_strdup(va_arg(ap, char *)));
	if (format.conversion == PTR_T)
		return (ft_vsnprintf_ap_ptr_to_str(ap, format));
	return (NULL);
}

static int			get_format_jump(ft_format_t format)
{
	int jump;

	jump = 1;
	if (format.len_mod == CHAR_MOD || format.len_mod == LONGLONG_MOD)
		jump += 2;
	else if (format.len_mod != NONE_MOD && !format.shorthand)
		jump++;
	return (jump);
}

static int			add_formatted_var(char *str, va_list ap,
									  const char *format_str)
{
	ft_format_t	format;
	char		*var_str;

	if (*format_str == '%')
	{
		ft_strcat(str, "%");
		return (1);
	}
	else
	{
		format = get_format_struct(format_str);
		if (format.conversion == NONE_T)
			return (0);
		if (!(var_str = ap_to_str(ap, format)))
			return (-1);
		ft_strcat(str, var_str);
		free(var_str);
		return (get_format_jump(format));
	}
}

int					ft_vsnprintf(char *str, size_t size, const char *format,
								 va_list ap)
{
	size_t	str_pos;
	int		increase;
	
	ft_bzero(str, size);
	str_pos = 0;
	while (*format && str_pos < size - 1)
	{
		if (*format == '%')
		{
			format++;
			if ((increase = add_formatted_var(str, ap, format)) == -1)
				return (-1);
			format += increase;
			str_pos = ft_strlen(str);
		}
		else
			str[str_pos++] = *format++;
	}
	return str_pos;
}
