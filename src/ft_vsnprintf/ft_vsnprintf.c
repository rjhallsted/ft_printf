/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:36:32 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/13 18:35:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static ft_format_t	get_format_struct(const char *format_str)
{
	ft_format_t format;
	const char	*str_hold;

	str_hold = format_str;
	ft_memset(format.flags, '.', 5);
	format.flags[5] = '\0';
	ft_vsnprintf_get_flags(&format, format_str);
	while (ft_strchr(FT_FORMAT_FLAGS, *format_str))
		   format_str++;
	format.field_width = ft_vsnprintf_get_field_width(format_str, format.flags);
	if (format.field_width)
		while (ft_isdigit(*format_str))
			format_str++;
	format.precision = ft_vsnprintf_get_precision(format_str);
	if (format.precision != -1)
	{
		format_str++;
		if (*format_str == '-')
			format_str++;
		while (ft_isdigit(*format_str))
			format_str++;
	}
	if (!(ft_vsnprintf_check_shorthand(format_str, &format)))
	{
		format.len_mod = ft_vsnprintf_get_len_mod(format_str);
		if (format.len_mod == CHAR_MOD || format.len_mod == LONGLONG_MOD)
			format_str += 2;
		else if (format.len_mod != NONE_MOD)
			format_str++;
		format.conversion = ft_vsnprintf_get_conversion(format_str);
		format.disp_mod = ft_vsnprintf_get_disp_mod(format_str);
	}
	format_str++;
	format.str_jump = format_str - str_hold;
	return (format);
}

static char			*ap_to_str(va_list ap, ft_format_t format, char *s)
{
	if (format.conversion == INT_T || format.conversion == CHAR_T)
		return (ft_vsnprintf_ap_int_to_str(ap, format, s));
	if (format.conversion == UINT_T)
		return (ft_vsnprintf_ap_uint_to_str(ap, format, s));
	if (format.conversion == STR_T)
		return (ft_vsnprintf_ap_str_to_str(ap, format, s));
	if (format.conversion == PTR_T)
		return (ft_vsnprintf_ap_ptr_to_str(ap, format, s));
	return (NULL);
}

static int			add_formatted_var(char *str, va_list ap,
									  const char *format_str)
{
	ft_format_t	format;

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
		if (!(ap_to_str(ap, format, str)))
			return (-1);
		return (format.str_jump);
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
			if ((increase = add_formatted_var(str + str_pos, ap, format)) == -1)
				return (-1);
			format += increase;
			str_pos = ft_strlen(str);
		}
		else
			str[str_pos++] = *format++;
	}
	return str_pos;
}
