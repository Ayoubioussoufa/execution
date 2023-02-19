/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:44:55 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/19 11:06:56 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int env_builtin(char *cmd, char **env)
{
	int	i;

	i = 0;
	if (!cmd[1])
	{
		while (env[i])
		{
			if (ft_strchr(env[i], '=') != -1)
				printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		// status = EXIT_FAILURE;
		return (ft_perror("minishell: env: Too many arguments.", NULL));
	}
	return (1);
}