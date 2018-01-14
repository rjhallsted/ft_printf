/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:36:44 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/14 13:53:37 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static void	handle_flags(t_format *format, char **s)
{
	char	*tmp;

	if (ft_strchr(format->flags, '#') && format->disp_mod != NONE_DISP
		&& **s != '0')
	{
		tmp = "";
		if (format->disp_mod == HEX_DISP)
			tmp = "0x";
		else if (format->disp_mod == HEX_UP_DISP)
			tmp = "0X";
		else if (format->disp_mod == OCT_DISP && **s != '0')
			tmp = "0";
		if (!ft_strchr(*s, ' ') || ft_strchr(format->flags, '-'))
		{
			tmp = ft_strjoin(tmp, *s);
			if ((int)ft_strlen(*s) == ABS(format->field_width)
				&& (ABS(format->field_width) > 0 || format->disp_mod == HEX_DISP || format->disp_mod == HEX_UP_DISP))
			{
				free(*s);
				*s = ft_strsub(tmp, 0, ABS(format->field_width));
				free(tmp);
			}
			else
			{
				free(*s);
				*s = tmp;
			}
		}
		else
		{
			if (ft_strnstr(*s, "  ", ft_strlen(*s)) && format->disp_mod != OCT_DISP)
			{
				if (ft_strchr(format->flags, '0'))
					ft_strncpy(*s, tmp, 2);
				else
					ft_strncpy(ft_strrchr(*s, ' ') - 1, tmp, 2);
			}
			else if (format->disp_mod == OCT_DISP)
				*(ft_strrchr(*s, ' ')) = '0';
			else
			{
				*s = ft_strjoinfree(" ", *s, 2);
				ft_strncpy(*s, tmp, ft_strlen(tmp));
			}
		}
	}
	if (ft_strchr(format->flags, ' ') && !ft_strchr(*s, '-')
		&& format->field_width > -1 && !format->is_nullchar && format->conversion != UINT_T)
		*s = ft_strjoinfree(" ", *s, 2);
	if (ft_strchr(format->flags, '0') && !ft_strchr(format->flags, '-')
		&& format->field_width > -1 && format->precision == -1)
	{
		ft_strreplace(*s, ' ', '0');
		if (ft_strchr(*s, '-'))
		{
			ft_strreplace(*s, '-', '0');
			**s = '-';
		}
	}
	if (ft_strchr(format->flags, '+') && !ft_strchr(*s, '-') && format->conversion != UINT_T
		&& ((**s == '0' && ft_strlen(*s) > 1) || **s == ' '))
	{
		if (ft_strchr(format->flags, '0') && **s == '0' && ft_strlen(*s) > 1)
			**s = '+';
		else if (ft_strchr(*s, ' ') && !ft_strchr(format->flags, '-'))
			*(ft_strrchr(*s, ' ')) = '+';
		else
		{
			*s = ft_strjoinfree("+", *s, 2);
			(*s)[format->field_width] = '\0';
		}
	}
	else if (ft_strchr(format->flags, '+') && !ft_strchr(*s, '-') && format->conversion != UINT_T)
		*s = ft_strjoinfree("+", *s, 2);
}

static void	handle_precision(t_format *format, char **s)
{
	char	*tmp;
	char	*tmp2;
	int		neg;

	neg = (**s == '-') ? 1 : 0;
	if (format->conversion == STR_T)
	{
		if (format->precision < (int)ft_strlen(*s) && format->precision > -1)
			ft_strclr(*s + format->precision);
	}
	else if (format->precision - (int)ft_strlen(*s) + neg > 0
		&& !format->is_nullchar)
	{
		tmp = ft_xstring('0', format->precision - ft_strlen(*s) + neg);
		tmp2 = (neg) ? ft_strjoinfree(tmp, (*s) + 1, 1) : ft_strjoinfree(tmp, *s, 1);
		free(*s);
		*s = (neg) ? ft_strjoinfree("-", tmp2, 2) : tmp2;
	}
	else if (format->precision == 0 && (format->disp_mod != NONE_DISP
							|| (ft_atoi(*s) == 0 && format->conversion != PERCENT_T)))
		ft_strclr(*s);
}


static void	handle_field_width(t_format *format, char **s)
{
	char	*padding;
	char	*tmp;
	int		len;
	int		right_side;

	len = (format->is_nullchar) ? 1 : ft_strlen(*s);
	right_side = (format->field_width < 0);
	format->field_width *= (right_side) ? -1 : 1;
	if (format->field_width <= len)
		return;
	if (format->flags[FLAGS_SPACE_KEY] && !right_side)
		format->field_width--;
	padding = ft_xstring(' ', format->field_width - len);
	if (right_side && format->is_nullchar)
	{
		free(*s);
		tmp = ft_strnew(ft_strlen(padding) + 1);
		*tmp = '\0';
		ft_strcat((tmp) + 1, padding);
	}
	else if (right_side)
		tmp = ft_strjoinfree(*s, padding, 3);
	else
		tmp = ft_strjoinfree(padding, *s, 3);
	*s = tmp;
}

#include <stdio.h>

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

void	ft_vprintf_process_return(t_format *format, char **s)
{
	if (1 == 2)
		print_format(format);
	
	handle_precision(format, s);
	handle_field_width(format, s);
	if (format->conversion != PERCENT_T)
		handle_flags(format, s);	
}
