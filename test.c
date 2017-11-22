/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:53:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 14:26:46 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
//	char *test = "test string";
	char *hold;
	hold = ft_strnew(100);
	ft_snprintf(hold, 100, "testing %s\n", "this");
	printf("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	ft_snprintf(hold, 100, "%dnd test\n", -2);
	printf("%s", hold);
	free(hold);

	hold = ft_strnew(100);
	ft_snprintf(hold, 100, "%u and %u test\n", 3, 13244214);
	printf("%s", hold);
	free(hold);
	return (0);
}
