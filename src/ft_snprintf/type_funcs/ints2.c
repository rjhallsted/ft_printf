/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:18:30 by suvitiel          #+#    #+#             */
/*   Updated: 2017/11/25 16:40:10 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../../inc/ft_printf.h"

 
long int			ft_vsnprintf_get_l_int(va_list ap)
{
	return (va_arg(ap, long int));
}

unsigned long int	ft_vsnprintf_get_ul_int(va_list ap)
{
	return (va_arg(ap, unsigned long int));
}

long long int		ft_vsnprintf_get_ll_int(va_list ap)
{
	return (va_arg(ap, long long int));
}

unsigned long long int	ft_vsnprintf_get_ull_int(va_list ap)
{
	return (va_arg(ap, unsigned long long int));
}
