/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:50:10 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 23:09:33 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../inc/libft.h"

void	ft_vprintf_apchar_to_str(t_format fmt, intmax_t signed_int, char **s)
{
	*s = ft_strnew(1);
	**s = (unsigned char)signed_int;
//	fmt.is_nullchar = (**s == '\0');
	if (**s == '\0')
		write(1, *s, 1);
	ft_vprintf_process_return(fmt, s);
}

void	ft_vprintf_apuint_helper(t_format *fmt, uintmax_t uint, char **s)
{
	unsigned int	b;

	b = (fmt->disp_mod == OCT_DISP) ? 8 : 10;
	b = (fmt->disp_mod == HEX_DISP || fmt->disp_mod == HEX_UP_DISP) ? 16 : b;
	if (fmt->disp_mod == HEX_UP_DISP)
	{
		*s = ft_uintmaxtoa_base(uint, b);
		ft_strtoup(*s);
	}
	else
		*s = ft_uintmaxtoa_base(uint, b);
}
