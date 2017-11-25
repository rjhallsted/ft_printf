/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:44:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/25 01:11:36 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

enum types {
	TYPE_INT = 1,
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
