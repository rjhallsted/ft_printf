/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:36:44 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/16 16:01:40 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static char	*handle_flags(t_format format, char *s)
{
	char	*tmp;

	if (ft_strchr(format.flags, '#') && format.disp_mod != NONE_DISP
		&& *s != '0')
	{
		tmp = "";
		if (format.disp_mod == HEX_DISP)
			tmp = "0x";
		else if (format.disp_mod == HEX_UP_DISP)
			tmp = "0X";
		else if (format.disp_mod == OCT_DISP && *s != '0')
			tmp = "0";
		if (!(ft_strchr(s, ' ')) || ft_strchr(format.flags, '-'))
		{
			if ((int)ft_strlen(s) == ABS(format.field_width)
				&& (ABS(format.field_width) > 0 || format.disp_mod == HEX_DISP || format.disp_mod == HEX_UP_DISP))
			{
				ft_strinsert(s, tmp, 0);
				s[ABS(format.field_width)] = '\0';
			}
			else
				ft_strinsert(s, tmp, 0);
		}
		else
		{
			if (ft_strnstr(s, "  ", ft_strlen(s)) && format.disp_mod != OCT_DISP)
			{
				if (ft_strchr(format.flags, '0'))
					ft_strncpy(s, tmp, 2);
				else
					ft_strncpy(ft_strrchr(s, ' ') - 1, tmp, 2);
			}
			else if (format.disp_mod == OCT_DISP)
				*(ft_strrchr(s, ' ')) = '0';
			else
			{
				ft_strinsert(s, " ", 0);
				ft_strncpy(s, tmp, ft_strlen(tmp));
			}
		}
	}
	if (ft_strchr(format.flags, ' ') && !ft_strchr(s, '-')
		&& format.field_width > -1)
		ft_strinsert(s, " ", 0);
	if (ft_strchr(format.flags, '0') && !ft_strchr(format.flags, '-')
		&& format.field_width > -1 && format.precision == -1)
		ft_strreplace(s, ' ', '0');
	if (ft_strchr(format.flags, '+') && !ft_strchr(s, '-')
		&& ((*s == '0' && ft_strlen(s) > 1) || *s == ' '))
		*s = '+';
	else if (ft_strchr(format.flags, '+') && !ft_strchr(s, '-'))
		ft_strinsert(s, "+", 0);
	return (s);
}

static char	*handle_precision(t_format format, char *s)
{
	char	*tmp;
	int		neg;

	neg = (*s == '-') ? 1 : 0;
	if (format.precision == -1)
		return (s);
	if (format.conversion == STR_T)
		s[format.precision] = '\0';
	else if (format.precision - (int)ft_strlen(s) + neg > 0
		&& !format.is_nullchar)
	{
		tmp = ft_xstring('0', format.precision - ft_strlen(s) + neg);
		ft_strinsert(s, tmp, neg);
	}
	else if (format.precision == 0 && format.disp_mod != NONE_DISP)								
		ft_strclr(s);
	return (s);
}

static char	*handle_field_width(t_format format, char *s)
{
	char	*padding;
	int		len;
	int		right_side;

	len = (format.is_nullchar) ? 1 : ft_strlen(s);
	right_side = (format.field_width < 0);
	format.field_width *= (right_side) ? -1 : 1;
	if (format.field_width <= len)
		return (s);
	if (ft_strchr(format.flags, ' ') && !right_side)
		format.field_width--;
	padding = ft_xstring(' ', format.field_width - len);
	if (right_side && format.is_nullchar)
		ft_strcat(s + 1, padding);
	else if (right_side)
		ft_strcat(s, padding);
	else
		ft_strinsert(s, padding, 0);
	free(padding);
	return (s);
}

char		*ft_vsnprintf_process_return(t_format format, char *s)
{
	s = handle_precision(format, s);
	s = handle_field_width(format, s);
	if (format.conversion != PERCENT_T)
		s = handle_flags(format, s);
	return (s);
}
