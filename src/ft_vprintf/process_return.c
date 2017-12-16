/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:36:44 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/16 12:53:54 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

#include <stdio.h>

static void	handle_flags(t_format format, char **s)
{
	char	*tmp;

	if (ft_strchr(format.flags, ' ') && !ft_strchr(*s, '-')
		&& format.field_width > -1)
		*s = ft_strjoinfree(" ", *s, 2);
	if (ft_strchr(format.flags, '#') && format.disp_mod != NONE_DISP
		&& **s != '0')
	{
		tmp = "";
		if (format.disp_mod == HEX_DISP)
			tmp = "0x";
		else if (format.disp_mod == HEX_UP_DISP)
			tmp = "0X";
		else if (format.disp_mod == OCT_DISP && **s != '0')
			tmp = "0";
		if (!ft_strchr(*s, ' '))
			*s = ft_strjoinfree(tmp, *s, 2);
		else
		{
			if (ft_strnstr(*s, "  ", ft_strlen(*s)) && format.disp_mod != OCT_DISP)
			{
				if (ft_strchr(format.flags, '0'))
					ft_strncpy(*s, tmp, 2);
				else
					ft_strncpy(ft_strrchr(*s, ' ') - 1, tmp, 2);
			}
			else if (format.disp_mod == OCT_DISP)
				**s = '0';
			else
			{
				*s = ft_strjoinfree(" ", *s, 2);
				ft_strncpy(*s, tmp, ft_strlen(tmp));
			}
		}
	}
	if (ft_strchr(format.flags, '0') && !ft_strchr(format.flags, '-')
		&& format.field_width > -1 && format.precision == -1)
		ft_strreplace(*s, ' ', '0');
	if (ft_strchr(format.flags, '+') && !ft_strchr(*s, '-')
		&& (**s == '0' || **s == ' '))
		**s = '+';
	else if (ft_strchr(format.flags, '+') && !ft_strchr(*s, '-'))
		*s = ft_strjoinfree("+", *s, 2);
}

static void	handle_precision(t_format format, char **s)
{
	char	*tmp;
	char	*tmp2;
	int		neg;

	neg = (**s == '-') ? 1 : 0;
	if (format.conversion == STR_T && format.precision > -1)
	{
		tmp = ft_strsub(*s, 0, format.precision);
		free(*s);
		*s = tmp;
	}
	else if (format.precision - (int)ft_strlen(*s) + neg > 0)
	{
		tmp = ft_xstring('0', format.precision - ft_strlen(*s) + neg);
		tmp2 = (neg) ? ft_strjoin(tmp, (*s) + 1) : ft_strjoin(tmp, *s);
		free(tmp);
		free(*s);
		*s = (neg) ? ft_strjoin("-", tmp2) : tmp2;
		if (neg)
			free(tmp2);
	}
}

static void	handle_field_width(t_format format, char **s)
{
	char	*padding;
	char	*tmp;
	int		len;
	int		right_side;

	len = (format.is_nullchar) ? 1 : ft_strlen(*s);
	right_side = (format.field_width < 0);
	format.field_width *= (right_side) ? -1 : 1;
	if (format.field_width <= len)
		return;
	if (ft_strchr(format.flags, ' ') && !right_side)
		format.field_width--;
	padding = ft_xstring(' ', format.field_width - len);
	if (right_side && format.is_nullchar)
	{
		free(*s);
		*s = ft_strnew(ft_strlen(padding) + 1);
		**s = '\0';
		ft_strcat((*s) + 1, padding);
		return;
	}
	else if (right_side)
		tmp = ft_strjoin(*s, padding);
	else
		tmp = ft_strjoin(padding, *s);
	free(*s);
	*s = tmp;
	free(padding);
}

void	ft_vprintf_process_return(t_format format, char **s)
{
	handle_precision(format, s);
	handle_field_width(format, s);
	if (format.conversion != PERCENT_T)
		handle_flags(format, s);	
}
