/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:03:52 by ahallain          #+#    #+#             */
/*   Updated: 2021/01/31 12:15:21 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

char	*env_get(char **env, char *name);
char	*env_set(char **env, char *key, char *value);
size_t	env_rm(char **env, char *key);
#endif
