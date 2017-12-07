/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:10:41 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 18:46:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_vsnprintf_check_shorthand(const char *format_str, ft_format_t *format)
{
	if (*format_str == 'D')
	{
		format->len_mod = LONG_MOD;
		format->conversion = INT_T;
		format->shorthand = 1;
		format->disp_mod = NONE_DISP;
		return (1);
	}
	if (*format_str == 'O' || *format_str == 'U')
	{
		format->len_mod = LONG_MOD;
		format->conversion = UINT_T;
		format->shorthand = 1;
		format->disp_mod = (*format_str == 'O') ? OCT_DISP : NONE_DISP;
		return (1);
	}
	format->shorthand = 0;
	return (0);
}

int	ft_vsnprintf_get_len_mod(const char *format_str)
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

int	ft_vsnprintf_get_conversion(const char *format_str)
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

int	ft_vsnprintf_get_disp_mod(const char *format_str)
{
	if (*format_str == 'x' || *format_str == 'X')
		return (HEX_DISP);
	if (*format_str == 'o')
		return (OCT_DISP);
	return (NONE_DISP);
}
