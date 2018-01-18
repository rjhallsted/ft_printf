/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:40:52 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/17 21:58:32 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static int		format_var(char **str, const char *format_str, va_list ap,
					t_format *format)
{
	ft_vprintf_determine_format(format_str, format);
	if (format->conversion == NONE_T)
		return (format->str_jump);
	if (format->conversion == PERCENT_T)
	{
		*str = ft_strdup("%");
		ft_vprintf_process_return(format, str);
	}
	else
		ft_vprintf_ap_to_str(ap, format, str);
	return (format->str_jump);
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

int				ft_vprintf(const char *fmt_str, va_list ap)
{
	int			increase;
	size_t		len;
	char		*str;
	char		*pos;
	t_format	format;

	str = NULL;
	len = 0;
	while (*fmt_str)
	{
		if (*fmt_str == '%')
		{
			fmt_str++;
			if ((increase = format_var(&str, fmt_str, ap, &format)) == -1)
				return (-1);
			fmt_str += increase;
			if (1 == 2)
				print_format(&format);
			if (format.is_nullchar)
				len++;
			if (format.is_nullchar == ISNULLCHAR_LEFT)
				write(1, "\0", 1);
			if (str && format.conversion != NONE_T)
			{
				len += ft_strlen(str);
				ft_putstr(str);
				free(str);
			}
			if (format.is_nullchar == ISNULLCHAR_RIGHT)
				write(1, "\0", 1);
		}
		else
		{
			if ((pos = ft_strchr(fmt_str, '%')))
			{
				write(1, fmt_str, pos - fmt_str);
				len += pos - fmt_str;
				fmt_str += pos - fmt_str;
			}
			else
			{
				ft_putstr(fmt_str);
				len += ft_strlen(fmt_str);
				fmt_str += ft_strlen(fmt_str);
			}
		}
	}
	return (len);
}
