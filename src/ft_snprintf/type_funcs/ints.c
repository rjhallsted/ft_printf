/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:03:13 by suvitiel          #+#    #+#             */
/*   Updated: 2017/11/25 16:41:35 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../../inc/ft_printf.h"

int				ft_vsnprintf_get_int(va_list ap)
{
	return (va_arg(ap, int));
}

unsigned int	ft_vsnprintf_get_uint(va_list ap)
{
	return (va_arg(ap, unsigned int));
}

short int		ft_vsnprintf_get_sh_int(va_list ap)
{
	return ((short int)va_arg(ap, int));
}

unsigned short int	ft_vsnprintf_get_ush_int(va_list ap)
{
	return ((unsigned short int)va_arg(ap, unsigned int));
}
