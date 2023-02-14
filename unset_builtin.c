/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:09:29 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/14 17:40:02 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*stdup(char **env, int i)
{
	char	*ev;
	int	length;
	int	j;

	j = 0;
	length = ft_strlen(env[i]);
	ev = malloc(length + 1);
	while (length > 0)
	{
		ev[j] = env[i][j];
		j++;
		length--;
	}
	ev[j] = '\0';
	return (ev);
}

void	removeit(char **env, char **ev, int index, int jndex)
{
	int	i;

	i = index;
	ev[i] = stdup(env, i + 1);
	i += 1;
	while (env[i] && i < jndex)
	{
		ev[i] = stdup(env, i + 1);
		i++;
	}
	ev[i] = 0;
}

char	**reallocate(char **ev, char **env, char *e)
{
	int	i;
	int	j;

	j = 0;
	while (ev[j])
		free(ev[j++]);
	free(ev);
    ev = malloc(j * sizeof(char *));
	i = 0;
	// printf("environment variable : %s\n", env[i]);
	// printf("E li sift : %s\n", e);
	int	s = strncmp(env[i], e, ft_strlen(e));
	// printf("%d\n", s);
	while (env[i] && strncmp(env[i], e, ft_strlen(e)))
	{
        ev[i] = stdup(env, i);
		// printf("%s\n", env[i]);
		// printf("%s\n", ev[i]);
		// printf("******\n");
		i++;
	}
	// printf("-----------------------------------\n");
	removeit(env, ev, i, j - 1);
	return (ev);
}

char    **shell_env(char **env)
{
    char    **ev;
	int	i;

	i = 0;
	while (env[i])
		i++;
    ev = malloc((i + 1) * sizeof(char *));
	i = -1;
    while (env[++i])
        ev[i] = stdup(env, i);
	return (ev);
}

int unset_builtin(char **env, char *cmd)
{
    char    **ev;
	char	**e;
	int	i;
	int	j;
	
	j = 0;
	(void)cmd;
	i = 0;
    ev = shell_env(env);
	while (env[j])
		j++;
	while (ev[i])
	{
		if (!strncmp(ev[i], cmd, ft_strlen(cmd)))
		{
			// printf("%s\n", ev[i]);
			e = reallocate(ev, env, cmd);
			break ;
		}
		i++;
	}
	i = 0;
	// printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	while (e[i] && i < j)
		printf("%s\n", e[i++]);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// int	i;

	// i = 0;
	// int	index;
	char	*cmd = "PATH";
	// while(env[i])
	// {
	// 	int	index = strncmp(env[i], cmd, ft_strlen(cmd));
	// 	printf("%d || %d\n", i, index);
	// 	i++;
	// }
	unset_builtin(env, cmd);
}