/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:29:05 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 21:06:27 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../inc/libft.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	size_t	print_len;

	va_start(ap, format);
	print_len = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (print_len);
}
