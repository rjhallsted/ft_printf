/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:45:54 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/04 11:39:58 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>

enum	e_types {
	NONE_T = -1,
	INT_T = 0,
	UINT_T,
	CHAR_T,
	STR_T,
	PTR_T,
	PERCENT_T
};

enum	e_len_mods {
	NONE_MOD = -1,
	CHAR_MOD = 0,
	SHORT_MOD,
	LONG_MOD,
	LONGLONG_MOD,
	INTMAX_MOD,
	SIZET_MOD
};

enum	e_display_mods {
	NONE_DISP = -1,
	HEX_DISP = 0,
	HEX_UP_DISP,
	OCT_DISP
};

enum	e_flag_keys {
	FLAGS_SPACE_KEY,
	FLAGS_SHARP_KEY,
	FLAGS_MINUS_KEY,
	FLAGS_PLUS_KEY,
	FLAGS_ZERO_KEY,
};

enum	e_isnullchar {
	ISNULLCHAR_NO,
	ISNULLCHAR_LEFT,
	ISNULLCHAR_RIGHT
};


# ifndef FT_FORMAT_FLAGS
#  define FT_FORMAT_FLAGS " #-+0"
# endif

typedef struct	s_ft_format
{
	char		flags[5];
	int			field_width;
	int			precision;
	int			len_mod;
	int			conversion;
	int			disp_mod;
	int			shorthand;
	size_t		str_jump;
	int			is_nullchar;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_snprintf(char *str, size_t size,
							const char *format, ...);
int				ft_vsnprintf(char *str, size_t size, const char *format,
							va_list ap);
int				ft_vsnprintf_check_shorthand(const char *format_str,
											t_format *format);
int				ft_vsnprintf_get_len_mod(const char *format_str);
int				ft_vsnprintf_get_conversion(const char *format_str);
int				ft_vsnprintf_get_disp_mod(const char *format_str);
int				ft_vsnprintf_get_precision(const char *format_str);
int				ft_vsnprintf_get_field_width(const char *format_str,
											char *flags);
void			ft_vsnprintf_get_flags(t_format *format,
										const char *format_str);
char			*ft_vsnprintf_ap_to_str(va_list ap, t_format format,
										char *s);
void			ft_vprintf_ap_to_str(va_list ap, t_format *format, char **s);
char			*ft_vsnprintf_process_return(t_format format,
											char *s);
void			ft_vprintf_process_return(t_format *format, char **s);
char			*ft_vsnprintf_apchar_to_str(t_format fmt,
											intmax_t signed_int, char *s);
void			ft_vprintf_apchar_to_str(t_format *fmt,
											intmax_t signed_int, char **s);
void			ft_vsnprintf_apuint_helper(t_format *fmt,
										uintmax_t uint, char *s);
void			ft_vprintf_apuint_helper(t_format *fmt,
										uintmax_t uint, char **s);
#endif
