/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:26:58 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 20:44:53 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int		ft_vsnprintf_check_shorthand(const char *fmt_str, t_format *format)
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
