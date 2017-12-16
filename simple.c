/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:01:02 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/16 11:59:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int main(void)
{
	ft_printf("%s\n", "TESTING it out");
	ft_printf("%+3d\n", 5);
	ft_printf("%+i\n", 42);
	ft_printf("%+*1d\n", 3);
	ft_printf("%   %\n");
	return (0);
}
