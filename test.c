/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 11:00:15 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>

int main(void)
{
	char *test = "test string";
	char *hold;
	hold = ft_strnew(ft_strlen(test));
	ft_snprintf(hold, ft_strlen(test), test);
	printf("%s\n", test);
	return (0);
}
