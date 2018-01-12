/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:32:11 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/11 21:45:52 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static const char	*set_flags(const char *format_str, t_format *format)
{
	char *flags;

	flags = format->flags;
	ft_bzero(flags, 5);
	while (ft_strchr(FT_FORMAT_FLAGS, *format_str))
	{
		if (*format_str == '#')
			flags[FLAGS_SHARP_KEY] = 1;
		if (*format_str == ' ')
			flags[FLAGS_SPACE_KEY] = 1;
		if (*format_str == '+')
			flags[FLAGS_PLUS_KEY] = 1;
		if (*format_str == '-')
			flags[FLAGS_MINUS_KEY] = 1;
		if (*format_str == '0')
			flags[FLAGS_ZERO_KEY] = 1;
		format_str++;
	}
	return (format_str);
}

static const char	*set_field_width(const char *format_str, t_format *format)
{
	int num;

	if (ft_isdigit(*format_str))
	{
		num = (format->flags[FLAGS_MINUS_KEY]) ? -1 : 1;
		num *= ft_atoi(format_str);
		format_str += ft_digitcount(num);
	}
	else
		num = 0;
	format->field_width = num;
	return (format_str);
}

static const char	*set_precision(const char *format_str, t_format *format)
{
	if (*format_str == '.')
	{
		format_str++;
		format->precision = (ft_isdigit(*format_str)) ? ft_atoi(format_str) : 0;
		if (ft_isdigit(*format_str))
			format_str += ft_digitcount(format->precision);
	}
	else
		format->precision = -1;
	return (format_str);
}

static const char	*set_len_mod(const char *format_str, t_format *format)
{
	if (*format_str == 'h')
	{
		format_str++;
		format->len_mod = (*format_str == 'h') ? CHAR_MOD : SHORT_MOD;
		if (format->len_mod == CHAR_MOD)
			format_str++;
	}
	else if (*format_str == 'l')
	{
		format_str++;
		format->len_mod = (*format_str == 'l') ? LONGLONG_MOD : LONG_MOD;
		if (format->len_mod == LONGLONG_MOD)
			format_str++;
	}
	else {
		if (*format_str == 'j')
			format->len_mod = INTMAX_MOD;
		else if (*format_str == 'z')
			format->len_mod = SIZET_MOD;
		else
			format->len_mod = NONE_MOD;
		if (format->len_mod != NONE_MOD)
			format_str++;
	}
	return (format_str);
}

/*
 * The indexes in this array correspond to e_types
 */
static const char *type_keys[] = { "diD", "ouxXOU", "cC", "s", "p", "%"};
static const char disp_keys[] = { 'x', 'X', 'o' };

static const char	*set_conversion(const char *format_str, t_format *format)
{
	int type;
	int disp;

	if (ft_strchr("DCUO", *format_str))
		format->len_mod = LONG_MOD;
	format->conversion = NONE_T;
	type = 0;
	while (type < 6 && format->conversion == NONE_T)
	{
		if (ft_strchr(type_keys[type], *format_str))
			format->conversion = type;
		type++;
	}
	format->disp_mod = NONE_MOD;
	disp = 0;
	while (disp < 3 && format->disp_mod == NONE_MOD)
	{
		if (disp_keys[disp] == *format_str)
			format->disp_mod = disp;
		disp++;
	}
//	if (ft_strchr("DCUO", *format_str))
		format_str++;
//	else if (format->conversion != NONE_T)
//		format_str += 2;
	return (format_str);
}

void	ft_vprintf_determine_format(const char *format_str, t_format *format)
{
	const char *start;

	start = format_str;
	format_str = set_flags(format_str, format);
	format_str = set_field_width(format_str, format);
	format_str = set_precision(format_str, format);
	format_str = set_len_mod(format_str, format);
	format_str = set_conversion(format_str, format);
	format->str_jump = format_str - start;
}