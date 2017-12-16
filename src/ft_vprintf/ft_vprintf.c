/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:40:52 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/16 11:32:29 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static char		*format_struct2(t_format *format, const char *format_str)
{
	format->precision = ft_vsnprintf_get_precision(format_str);
	if (format->precision != -1)
	{
		format_str++;
		if (*format_str == '-')
			format_str++;
		while (ft_isdigit(*format_str))
			format_str++;
	}
	if (!(ft_vsnprintf_check_shorthand(format_str, format)))
	{
		format->len_mod = ft_vsnprintf_get_len_mod(format_str);
		if (format->len_mod == CHAR_MOD || format->len_mod == LONGLONG_MOD)
			format_str += 2;
		else if (format->len_mod != NONE_MOD)
			format_str++;
		format->conversion = ft_vsnprintf_get_conversion(format_str);
		format->disp_mod = ft_vsnprintf_get_disp_mod(format_str);
	}
	format_str++;
	format->is_nullchar = 0;
	return ((char *)format_str);
}

static t_format	get_format_struct(const char *format_str)
{
	t_format	format;
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
	format_str = format_struct2(&format, format_str);
	format.str_jump = format_str - str_hold;
	return (format);
}

static int			format_var(char **str, const char *format_str, va_list ap)
{
	t_format	format;

	if (*format_str == '%')
	{
		*str = ft_strdup("%");
		return (1);
	}
	else
	{
		format = get_format_struct(format_str);
		if (format.conversion == NONE_T)
			return (0);
		ft_vprintf_ap_to_str(ap, format, str);
		return (format.str_jump);
	}
}

int				ft_vprintf(const char *format, va_list ap)
{
	int		increase;
	size_t	len;
	char	*str;
	char	*pos;

	str = NULL;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((increase = format_var(&str, format, ap)) == -1)
				return (-1);
			format += increase;
			if (str)
			{
				len += ft_strlen(str); // this won't be correct when you write a nullchar
				ft_putstr(str);
				free(str);
			}
		}
		else
		{
			if ((pos = ft_strchr(format, '%')))
			{
				str = ft_strsub(format, 0, (size_t)(pos - format));
				format += ft_strlen(str);
				len += ft_strlen(str);
				ft_putstr(str);
				free(str);
			}
			else
			{
				ft_putstr(format);
				len += ft_strlen(format);
				format += ft_strlen(format);
			}
		}
	}
	return (len);
}
