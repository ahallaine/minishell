/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:03:49 by ahallain          #+#    #+#             */
/*   Updated: 2021/01/31 13:53:24 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "lib.h"

char	*env_get(char **env, char *key)
{
	char	*name;
	bool	equal;

	while (*env)
	{
		name = ft_strndup(*env, ft_strlen(*env, '='));
		equal = ft_equals(name, key);
		free(name);
		if (equal)
			return (*env + ft_strlen(*env, '=') + 1);
		env++;
	}
	return ("");
}

char	*env_set(char **env, char *key, char *value)
{
	size_t	index;
	char	*name;
	bool	equal;

	index = 0;
	while (env[index])
	{
		name = ft_strndup(env[index], ft_strlen(env[index], '='));
		equal = ft_equals(name, key);
		free(name);
		if (equal)
			break ;
		index++;
	}
	if (env[index])
		free(env[index]);
	if (!(env[index] = malloc(sizeof(char *))))
		return (0);
	*(env[index]) = 0;
	ft_stradd(&env[index], key);
	ft_stradd(&env[index], "=");
	ft_stradd(&env[index], value);
	return (env[index]);
}

size_t	env_rm(char **env, char *key)
{
	size_t	index;
	size_t	length;
	size_t	total_length;
	char	*name;

	index = 0;
	length = 0;
	while (env[index])
	{
		name = ft_strndup(env[index], ft_strlen(env[index], '='));
		if (ft_equals(name, key))
		{
			free(env[index]);
			length++;
		}
		else
			env[index - length] = env[index];
		free(name);
		index++;
	}
	total_length = index;
	index = total_length - length - 1;
	while (++index < total_length)
		env[index] = 0;
	return (length);
}
