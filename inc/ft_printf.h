/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:44:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/04 11:32:54 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>

int					ft_snprintf(char *str, size_t size,
								const char *format, ...);
int					ft_vsnprintf(char *str, size_t size,
								const char *format, va_list ap);

#endif
