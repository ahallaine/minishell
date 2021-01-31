/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:01:30 by ahallain          #+#    #+#             */
/*   Updated: 2021/01/31 10:31:57 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/lib.h"
#include "functions/functions.h"

int	call_function(char **args, char **env, int last_output)
{
	int			ret;

	(void)env;
	ret = 256;
	if (ft_equals(*args, "echo"))
		ret = f_echo(args);
	else if (ft_equals(*args, "exit"))
		ret = f_exit(args, last_output);
	else if (ft_equals(*args, "cd"))
		ret = f_cd(args, env);
	return (ret);
}