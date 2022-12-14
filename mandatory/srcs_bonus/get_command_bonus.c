/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:33:11 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/16 18:04:48 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static  char    **get_path(char *env[])
{
    char    **paths;
    int     i;

    i = 0;
    while(env[i] && ft_strncmp(env[i], "PATH=", 5))
        i++;
    if (!env[i])
        return (NULL);
    paths = ft_split(env[i] + 5, ':');
    return (paths);
}

void ft_get_cmd_path(char *cmd, char *env[])
{
    char    **paths;
    char    *path;
    char    *add_slash;
    int     i;

    paths = get_path(env);
    if (!paths)
        return ;
    i = 0;
    while(paths[i])
    {
        add_slash = ft_strjoin(paths[i], "/");
        path = ft_strjoin(add_slash, cmd);
        free(add_slash);
        if(!access(path, F_OK) && !access(path, X_OK))
            execve(path, paths, env);
        i++;
        free(path);
    }
    free_2d(paths);
}