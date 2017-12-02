/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:37:00 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/01 16:17:52 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/ft_printf.h"

void *ft_vsnprintf_func_dispatch(int type)
{
	void *funcs[18];

	funcs[TYPE_INT] = &ft_vsnprintf_get_int;
	funcs[TYPE_UINT] = &ft_vsnprintf_get_uint;
	funcs[TYPE_SH_INT] = &ft_vsnprintf_get_sh_int;
	funcs[TYPE_USH_INT] = &ft_vsnprintf_get_ush_int;
	funcs[TYPE_L_INT] = &ft_vsnprintf_get_l_int;
	funcs[TYPE_UL_INT] = &ft_vsnprintf_get_ul_int;
	funcs[TYPE_LL_INT] = &ft_vsnprintf_get_ll_int;
	funcs[TYPE_ULL_INT] = &ft_vsnprintf_get_ull_int;
	funcs[TYPE_WINT] = &ft_vsnprintf_get_wint;
	funcs[TYPE_CHAR] = &ft_vsnprintf_get_char;
	funcs[TYPE_UCHAR] = &ft_vsnprintf_get_uchar;
	funcs[TYPE_STR] = &ft_vsnprintf_get_str;
	funcs[TYPE_WCHAR] = &ft_vsnprintf_get_wchar;
	funcs[TYPE_INTMAX] = &ft_vsnprintf_get_intmax;
	funcs[TYPE_UINTMAX] = &ft_vsnprintf_get_uintmax;
	funcs[TYPE_SSIZET] = &ft_vsnprintf_get_ssize_t;
	funcs[TYPE_SIZET] = &ft_vsnprintf_get_size_t;
	funcs[TYPE_PTR] = &ft_vsnprintf_get_ptr;

	return (funcs[type]);
}
