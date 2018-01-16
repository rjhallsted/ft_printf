/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:36:44 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/15 16:49:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static void	handle_sharp_flag(t_format *format, char **s)
{
	char 	*tmp;

	if (format->flags[FLAGS_SHARP_KEY] && format->disp_mod != NONE_DISP
		&& **s != '0' && (ft_strlen(*s) > 0 || format->disp_mod == OCT_DISP))
	{
		tmp = ft_strdup("0x");
		tmp[1] = (format->disp_mod == HEX_UP_DISP) ? 'X' : tmp[1];
		tmp[1] = (format->disp_mod == OCT_DISP) ? '\0' : tmp[1];
		*s = ft_strjoinfree(tmp, *s, 3);
	}
}

static void	handle_flags(t_format *format, char **s)
{
	char *tmp;
	handle_sharp_flag(format, s);
	if (format->flags[FLAGS_SPACE_KEY] && **s != '-' && format->field_width > -1
		&& !format->is_nullchar && format->conversion != UINT_T)
	{
		tmp = (format->flags[FLAGS_ZERO_KEY]) ? "0" : " ";
		*s = ft_strjoinfree(tmp, *s, 2);
	}
	if (format->flags[FLAGS_ZERO_KEY] && format->field_width > (int)ft_strlen(*s)
		&& format->precision == -1 && !(format->flags[FLAGS_MINUS_KEY]))
	{
		tmp = ft_xstring('0', format->field_width - ft_strlen(*s));
		*s = ft_strjoinfree(tmp, *s, 3);
		tmp = ft_strdup("0x");
		tmp[1] = (format->disp_mod == HEX_UP_DISP) ? 'X' : tmp[1];
		if ((format->disp_mod == HEX_DISP || format->disp_mod == HEX_UP_DISP)
			&& ft_strstr(*s, tmp))
		{
			ft_memset(ft_strstr(*s, tmp), '0', 2);
			ft_strncpy(*s, tmp, 2);
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
	if (format->conversion != PERCENT_T)
		handle_flags(format, s);
	handle_field_width(format, s);
}
