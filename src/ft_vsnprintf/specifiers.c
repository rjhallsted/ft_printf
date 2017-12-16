/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:10:41 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 20:56:34 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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

void	ft_vsnprintf_get_flags(t_format *format, const char *format_str)
{
	char *flags;

	flags = format->flags;
	while (ft_strchr(FT_FORMAT_FLAGS, *format_str))
	{
		if (*format_str == '#')
			flags[FLAGS_SHARP_KEY] = '#';
		if (*format_str == ' ')
			flags[FLAGS_SPACE_KEY] = ' ';
		if (*format_str == '+')
			flags[FLAGS_PLUS_KEY] = '+';
		if (*format_str == '-')
			flags[FLAGS_MINUS_KEY] = '-';
		if (*format_str == '0')
			flags[FLAGS_ZERO_KEY] = '0';
		format_str++;
	}
}
