/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:40:52 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/16 14:45:20 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	format->is_nullchar = ISNULLCHAR_NO;
	return ((char *)format_str);
}

static void		set_format_struct(const char *format_str, t_format *format)
{
	const char	*str_hold;

	str_hold = format_str;
	ft_memset(format->flags, '.', 5);
	format->flags[5] = '\0';
	ft_vsnprintf_get_flags(format, format_str);
	while (ft_strchr(FT_FORMAT_FLAGS, *format_str))
		format_str++;
	format->field_width = ft_vsnprintf_get_field_width(format_str, format->flags);
	if (format->field_width)
		while (ft_isdigit(*format_str))
			format_str++;
	format_str = format_struct2(format, format_str);
	format->str_jump = format_str - str_hold;
}

static int		format_var(char **str, const char *format_str, va_list ap, t_format *format)
{
	set_format_struct(format_str, format);
	if (format->conversion == NONE_T)
		return (0);
	if (format->conversion == PERCENT_T)
	{
		*str = ft_strdup("%");
		ft_vprintf_process_return(format, str);
	}
	else
		ft_vprintf_ap_to_str(ap, format, str);
	return (format->str_jump);
}

int				ft_vprintf(const char *fmt_str, va_list ap)
{
	int			increase;
	size_t		len;
	char		*str;
	char		*pos;
	t_format	format;

	str = NULL;
	len = 0;
	while (*fmt_str)
	{
		if (*fmt_str == '%')
		{
			fmt_str++;
			if ((increase = format_var(&str, fmt_str, ap, &format)) == -1)
				return (-1);
			fmt_str += increase;
			if (format.is_nullchar)
				len++;
			if (format.is_nullchar == ISNULLCHAR_LEFT)
				write(1, "\0", 1);
			if (str)
			{
				len += ft_strlen(str);
				ft_putstr(str);
				free(str);
			}
			if (format.is_nullchar == ISNULLCHAR_RIGHT)
				write(1, "\0", 1);
		}
		else
		{
			if ((pos = ft_strchr(fmt_str, '%')))
			{
				str = ft_strsub(fmt_str, 0, (size_t)(pos - fmt_str));
				fmt_str += ft_strlen(str);
				len += ft_strlen(str);
				ft_putstr(str);
				free(str);
			}
			else
			{
				ft_putstr(fmt_str);
				len += ft_strlen(fmt_str);
				fmt_str += ft_strlen(fmt_str);
			}
		}
	}
	return (len);
}
