/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:44:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/25 00:23:18 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

enum types {
	TYPE_INT = 1,
	TYPE_UINT,
	TYPE_SH_INT,
	TYPE_L_INT,
	TYPE_WINT,
	TYPE_STR,
	TYPE_WCHAR,
	TYPE_INTMAX,
	TYPE_SIZET,
	TYPE_PTR 
};

#endif
