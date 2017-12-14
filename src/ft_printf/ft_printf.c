/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:01:29 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/13 20:14:26 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../inc/libft.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	size_t	len;
	
	str = ft_strnew(1000);
	va_start(ap, format);
	len = ft_vsnprintf(str, 1000, format, ap);
	va_end(ap);
	printf("len: %zu\n", len);
	write(1, str, len);
	free(str);
	return (len);
}
