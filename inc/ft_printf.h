/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:44:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/05 21:31:35 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>

enum types {
	NONE_T = -1,
	INT_T = 0,
	UINT_T,
	STR_T,
	PTR_T
};

enum len_mods {
	NONE_MOD = -1,
	CHAR_MOD = 0,
	SHORT_MOD,
	LONG_MOD,
	LONGLONG_MOD,
	INTMAX_MOD,
	SIZET_MOD
};		

typedef struct	ft_format_s
{
	char		*flags;
	size_t		field_width;
	size_t		precision;
	int			len_mod;
	int			conversion;
}				ft_format_t;

int				ft_printf(const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_vsnprintf(char *str, size_t size, const char *format,
							va_list ap);
int				ft_vsnprintf_check_shorthand(const char *format_str,
											 ft_format_t *format);
int				ft_vsnprintf_get_len_mod(const char *format_str);
int				ft_vsnprintf_get_conversion(const char *format_str);
char			*ft_vsnprintf_ap_int_to_str(va_list ap, ft_format_t format);
char			*ft_vsnprintf_ap_uint_to_str(va_list ap, ft_format_t format);
char			*ft_vsnprintf_ap_ptr_to_str(va_list ap, ft_format_t format);

#endif
