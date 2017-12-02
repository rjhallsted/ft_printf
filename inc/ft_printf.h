/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:44:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/02 12:50:56 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>

int						ft_vsnprintf_ap_to_str(char *str, va_list ap, const char *format);
char					*ft_vsnprintf_ap_to_str_char(va_list ap, int arg_type);
char					*ft_vsnprintf_ap_to_str_hex(va_list ap, int arg_type);
char					*ft_vsnprintf_ap_to_str_octal(va_list ap, int arg_type);
char					*ft_vsnprintf_ap_to_str_percent(void);
char					*ft_vsnprintf_ap_to_str_ptr(va_list ap, int arg_type);
char					*ft_vsnprintf_ap_to_str_sdec(va_list ap, int arg_type);
char					*ft_vsnprintf_ap_to_str_str(va_list ap, int arg_type);
char					*ft_vsnprintf_ap_to_str_udec(va_list ap, int arg_type);
void					*ft_vsnprintf_func_dispatch(int type);
int						ft_vsnprintf_get_int(va_list ap);
unsigned int			ft_vsnprintf_get_uint(va_list ap);
short int				ft_vsnprintf_get_sh_int(va_list ap);
unsigned short int		ft_vsnprintf_get_ush_int(va_list ap);
long int				ft_vsnprintf_get_l_int(va_list ap);
unsigned long int		ft_vsnprintf_get_ul_int(va_list ap);
long long int			ft_vsnprintf_get_ll_int(va_list ap);
unsigned long long int	ft_vsnprintf_get_ull_int(va_list ap);
wint_t					ft_vsnprintf_get_wint(va_list ap);
char					ft_vsnprintf_get_char(va_list ap);
unsigned char			ft_vsnprintf_get_uchar(va_list ap);
char					*ft_vsnprintf_get_str(va_list ap);
wchar_t					ft_vsnprintf_get_wchar(va_list ap);
intmax_t				ft_vsnprintf_get_intmax(va_list ap);
uintmax_t				ft_vsnprintf_get_uintmax(va_list ap);
ssize_t					ft_vsnprintf_get_ssize_t(va_list ap);
size_t					ft_vsnprintf_get_size_t(va_list ap);
void					*ft_vsnprintf_get_ptr(va_list ap);

enum types {
	TYPE_INT,
	TYPE_UINT,
	TYPE_SH_INT,
	TYPE_USH_INT,
	TYPE_L_INT,
	TYPE_UL_INT,
	TYPE_LL_INT,
	TYPE_ULL_INT,
	TYPE_WINT,
	TYPE_CHAR,
	TYPE_UCHAR,
	TYPE_STR,
	TYPE_WCHAR,
	TYPE_INTMAX,
	TYPE_UINTMAX,
	TYPE_SSIZET,
	TYPE_SIZET,
	TYPE_PTR 
};

#endif
