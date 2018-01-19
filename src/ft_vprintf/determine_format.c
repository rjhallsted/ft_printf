/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:32:11 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/18 17:21:47 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static const char	*set_flags(const char *format_str, t_format *format)
{
	while (*format_str && ft_strchr(FT_FORMAT_FLAGS, *format_str))
	{
		if (*format_str == '#')
			format->flags[FLAGS_SHARP_KEY] = 1;
		if (*format_str == ' ')
			format->flags[FLAGS_SPACE_KEY] = 1;
		if (*format_str == '+')
			format->flags[FLAGS_PLUS_KEY] = 1;
		if (*format_str == '-')
			format->flags[FLAGS_MINUS_KEY] = 1;
		if (*format_str == '0')
			format->flags[FLAGS_ZERO_KEY] = 1;
		format_str++;
	}
	return (format_str);
}

static const char	*set_field_width(const char *format_str, t_format *format)
{
	if (ft_isdigit(*format_str))
	{
		format->field_width = (format->flags[FLAGS_MINUS_KEY]) ? -1 : 1;
		format->field_width *= ft_atoi(format_str);
		format_str += ft_digitcount(ABS(format->field_width));
	}
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
	else if (*format_str == 'j')
	{
		format->len_mod = INTMAX_MOD;
		format_str++;
	}
	else if (*format_str == 'z')
	{
		format->len_mod = SIZET_MOD;
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
	int i;

	if (ft_strchr("DCUO", *format_str))
		format->len_mod = LONG_MOD;
	i = 0;
	while (i < 6 && format->conversion == NONE_T)
	{
		if (ft_strchr(type_keys[i], *format_str))
			format->conversion = i;
		i++;
	}
	format->disp_mod = NONE_MOD;
	i = 0;
	while (i < 3 && format->disp_mod == NONE_MOD)
	{
		if (disp_keys[i] == *format_str)
			format->disp_mod = i;
		i++;
	}
	if (format->conversion != NONE_T)
		format_str++;
	return (format_str);
}

static void init_format(t_format *format)
{
	ft_bzero(format->flags, 5);
	format->conversion = NONE_T;
	format->field_width = 0;
	format->precision = -1;
	format->len_mod = NONE_MOD;
	format->disp_mod = NONE_DISP;
	format->shorthand = 0;
	format->str_jump = 0;
	format->is_nullchar = ISNULLCHAR_NO;
}
static void	print_format(t_format *format)
{
	printf("--------------\n");
	printf("Flags:\n");
	if( format->flags[FLAGS_SPACE_KEY])
		printf("->space\n");
	if( format->flags[FLAGS_SHARP_KEY])
		printf("->sharp\n");
	if (format->flags[FLAGS_MINUS_KEY])
		printf("->minus\n");
	if (format->flags[FLAGS_PLUS_KEY])
		printf("->plus\n");
	if (format->flags[FLAGS_ZERO_KEY])
		printf("->zero\n");
	printf("Field width-> %d\n", format->field_width);
	printf("Precision-> %d\n", format->precision);
	printf("len_mod-> %d\n", format->len_mod);
	printf("conversion-> %d\n", format->conversion);
	printf("disp_mod-> %d\n", format->disp_mod);
	printf("shorthand-> %d\n", format->shorthand);
	printf("str_jump-> %zu\n", format->str_jump);
	printf("is_nullchar-> %d\n", format->is_nullchar);
	printf("-------------\n");
}

void	ft_vprintf_determine_format(const char *format_str, t_format *format)
{
	const char *start;

	init_format(format);
	start = format_str;
	while (ft_strchr(FT_PRINTF_VALCHAR, *format_str)
		&& format->conversion == NONE_T)
	{
		format_str = set_flags(format_str, format);
		format_str = set_field_width(format_str, format);
		format_str = set_precision(format_str, format);
		format_str = set_len_mod(format_str, format);
		format_str = set_conversion(format_str, format);
		if (1 == 2)
			print_format(format);
	}
	format->str_jump = format_str - start;
}
