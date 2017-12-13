/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:10:41 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/12 17:10:17 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int		ft_vsnprintf_check_shorthand(const char *fmt_str, ft_format_t *format)
{
	if (ft_strchr("DCOU", *fmt_str))
	{
		format->len_mod = LONG_MOD;
		format->shorthand = 1;
		format->disp_mod = NONE_DISP;
	}
	else
		format->shorthand = 0;
	if (*fmt_str == 'D')
		format->conversion = INT_T;
	if (*fmt_str == 'C')
		format->conversion = CHAR_T;
	if (*fmt_str == 'O' || *fmt_str == 'U')
	{
		format->conversion = UINT_T;
		format->disp_mod = (*fmt_str == 'O') ? OCT_DISP : NONE_DISP;
	}
	return (format->shorthand);
}

int		ft_vsnprintf_get_len_mod(const char *format_str)
{
	if (*format_str == 'h')
	{
		format_str++;
		return ((*format_str == 'h') ? CHAR_MOD : SHORT_MOD);
	}
	if (*format_str == 'l')
	{
		format_str++;
		return ((*format_str == 'l') ? LONGLONG_MOD : LONG_MOD);
	}
	if (*format_str == 'j')
		return (INTMAX_MOD);
	if (*format_str == 'z')
		return (SIZET_MOD);
	return (NONE_MOD);
}

int		ft_vsnprintf_get_conversion(const char *format_str)
{
	if (*format_str == 'c' || *format_str == 'C')
		return (CHAR_T);
	if (*format_str == 'd' || *format_str == 'i')
		return (INT_T);
	if (ft_strchr("ouxX", *format_str))
		return (UINT_T);
	if (*format_str == 's')
		return (STR_T);
	if (*format_str == 'p')
		return (PTR_T);
	return (NONE_T);
}

int		ft_vsnprintf_get_disp_mod(const char *format_str)
{
	if (*format_str == 'x')
		return (HEX_DISP);
	if (*format_str == 'X')
		return (HEX_UP_DISP);
	if (*format_str == 'o')
		return (OCT_DISP);
	return (NONE_DISP);
}

int		ft_vsnprintf_get_precision(const char *format_str)
{
	int precision;
	
	if (*format_str != '.')
		return (-1);
	format_str++;
	if (ft_isdigit(*format_str))
	{
		precision = ft_atoi(format_str);
		return ((precision > 0) ? precision : 0);
	}
	else
		return (0);
}

int		ft_vsnprintf_get_field_width(const char *format_str, char *flags)
{
	int num;
	
	num = (ft_strchr(flags, '-')) ? -1 : 1;
	num *= ft_atoi(format_str);
	return (num);
}

void	ft_vsnprintf_get_flags(ft_format_t *format, const char *format_str)
{
	char *flags;

	flags = format->flags;
	while (ft_strchr(FT_FORMAT_FLAGS, *format_str))
	{
		if (*format_str == ' ')
			flags[FLAGS_SPACE_KEY] = ' ';
		if (*format_str == '-')
			flags[FLAGS_MINUS_KEY] = '-';
		format_str++;
	}
}
