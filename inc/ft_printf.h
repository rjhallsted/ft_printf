/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:44:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/04 12:05:01 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>

struct		ft_format_s
{
	char	*flags;
	size_t	field_width;
	size_t	precision;
	int		len_mod;
	int		conversion;
};

int			ft_printf(char *format, ...);
int			ft_snprintf(char *str, size_t size, const char *format, ...);
int			ft_vsnprintf(char *str, size_t size, const char *format,
						 va_list ap);
#endif
