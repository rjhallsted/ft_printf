/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_format_wrapper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:43:49 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/18 18:45:48 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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

void	ft_vprintf_determine_format(const char *format_str, t_format *format)
{
	const char *start;

	init_format(format);
	start = format_str;
	while (ft_strchr(FT_PRINTF_VALCHAR, *format_str)
		&& format->conversion == NONE_T)
	{
		format_str = ft_vprintf_set_flags(format_str, format);
		format_str = ft_vprintf_set_field_width(format_str, format);
		format_str = ft_vprintf_set_precision(format_str, format);
		format_str = ft_vprintf_set_len_mod(format_str, format);
		format_str = ft_vprintf_set_conversion(format_str, format);
	}
	format->str_jump = format_str - start;
}
