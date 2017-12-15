/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:50:10 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 00:06:09 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

char *ft_vsnprintf_apchar_to_str(ft_format_t fmt, intmax_t signed_int, char *s)
{
	*s = (unsigned char)signed_int;
	*(s + 1) = '\0';
	fmt.is_nullchar = (*s == '\0');
	return (ft_vsnprintf_process_return(fmt, s));
}

void ft_vsnprintf_apuint_helper(ft_format_t *fmt, uintmax_t uint, char *s)
{
	char *new;
	unsigned int b;
	
	b = (fmt->disp_mod == OCT_DISP) ? 8 : 10;
	b = (fmt->disp_mod == HEX_DISP || fmt->disp_mod == HEX_UP_DISP) ? 16 : b;
	if (fmt->disp_mod == HEX_UP_DISP)
	{
		new = ft_uintmaxtoa_base(uint, b);
		ft_strtoup(new);
	}
	else
		new = ft_uintmaxtoa_base(uint, b);
	ft_strcpy(s, new);
	free(new);
}
