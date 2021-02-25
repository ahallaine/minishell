/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:21:09 by ahallain          #+#    #+#             */
/*   Updated: 2021/02/25 20:14:43 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../utils/lib.h"

char	f_exit(char **args)
{
	size_t	index;

	if (!args[1])
		return (-1);
	index = 0;
	while (args[1][index]
		&& args[1][index] >= '0'
		&& args[1][index] <= '9')
		index++;
	if (args[1][index])
	{
		ft_putstr_fd("numeric argument required\n", 2);
		errno = 2;
	}
	else if (args[2])
	{
		ft_putstr_fd("too many arguments\n", 2);
		return (1);
	}
	return (-1);
}
