/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 11:58:07 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>

int main(void)
{
//	char *test = "test string";
	char *hold;
	hold = ft_strnew(100);
	ft_snprintf(hold, 100, "testing %s\n", "this");
	printf("%s", hold);
	return (0);
}
