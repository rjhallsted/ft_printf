/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:10:41 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/05 22:40:53 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_vsnprintf_check_shorthand(const char *format_str, ft_format_t *format)
{
	if (*format_str == 'D')
	{
		format->len_mod = LONG_MOD;
		format->conversion = INT_T;
		return (1);
	}
	if (*format_str == 'O' || *format_str == 'U')
	{
		format->len_mod = LONG_MOD;
		format->conversion = UINT_T;
		return (1);
	}
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
	if (ft_strchr("cC", *format_str))
		return (CHAR_T);
	if (ft_strchr("di", *format_str))
		return (INT_T);
	if (ft_strchr("ouxX", *format_str))
		return (UINT_T);
	if (ft_strchr("sS", *format_str))
		return (STR_T);
	if (*format_str == 'p')
		return (PTR_T);
	return (NONE_T);
}
