/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:09:29 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/17 15:04:28 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// char	*stdup(char **env, int i)
// {
// 	char	*ev;
// 	int	length;
// 	int	j;

// 	j = 0;
// 	length = ft_strlen(env[i]) - 1;
// 	ev = malloc(length * (sizeof(char)));
// 	while (length > j)
// 	{
// 		ev[j] = env[i][j];
// 		j++;
// 	}
// 	ev[j] = '\0';
// 	return (ev);
// }

// void	removeit(char **env, char **ev, int index, int jndex)
// {
// 	int	i;

// 	i = index;
// 	ev[i] = stdup(env, i + 1);
// 	i += 1;
// 	while (env[i] && i < jndex)
// 	{
// 		ev[i] = stdup(env, i + 1);
// 		i++;
// 	}
// 	ev[i] = 0;
// }

// void	remove_it(char **env, char **ev, int index, int jndex)
// {
// 	int	i;

// 	i = index;
// 	ev[i] = stdup(env, i + 1);
// 	i += 1;
// 	while (env[i] && i < jndex)
// 	{
// 		ev[i] = stdup(env, i + 1);
// 		i++;
// 	}
// 	ev[i] = 0;
// }

// char	**reallocate(char **ev, char **env, char *e)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (ev[j])
// 		free(ev[j++]);
// 	free(ev);
//     ev = malloc(j * sizeof(char *));
// 	i = 0;
// 	while (env[i] && strncmp(env[i], e, ft_strlen(e)))
// 	{
//         ev[i] = stdup(env, i);
// 		i++;
// 	}
// 	removeit(env, ev, i, j - 1);
// 	return (ev);
// }

// char	**re_allocate(char **ev, char *cmd)
// {
// 	int	i = 0;
// 	char	**env;
// 	int	j;

// 	j = 0;
// 	while (ev[j])
// 		j++;
// 	i = 0;
// 	env = malloc(j * sizeof(char *));
// 	while (ev[i] && strncmp(ev[i], cmd, ft_strlen(cmd)))
// 	{
//         env[i] = stdup(ev, i);
// 		i++;
// 	}
// 	remove_it(ev, env, i, j - 1);
// 	j = 0;
// 	while (ev[j])
// 		free(ev[j++]);
// 	free(ev);
// 	return (env);
// }

// char    **shell_env(char **env)
// {
//     char    **ev;
// 	int	i;

// 	i = 0;
// 	while (env[i++])
// 		;
//     ev = malloc((i + 1) * sizeof(char *));
// 	i = -1;
// 	while (env[++i])
// 		ev[i] = env[i];
// 	i = -1;
//     while (env[++i])
//         ev[i] = stdup(env, i);
// 	ev[i] = 0;
// 	return (ev);
// }

// void unset_builtin(char **env, char *cmd)
// {
//     char    **ev = NULL;
// 	static char	**e;
// 	static	int x;
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	if (!x)
// 	{
// 		ev = shell_env(env);
// 		while (ev[i])
// 		{
// 			if (!strncmp(ev[i], cmd, ft_strlen(cmd)))
// 			{
// 				e = reallocate(ev, env, cmd);
// 				break ;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		x++;
// 	}
// 	else
// 	{
// 		while (e[i])
// 		{
// 			if (!strncmp(e[i], cmd, ft_strlen(cmd)))
// 			{
// 				e = re_allocate(e, cmd);
// 				break ;
// 			}
// 			i++;
// 		}
// 	}
// 	// i = 0;
// 	// while (e[j])
// 	// 	j++;
// 	// while (e[i] && i < j)
// 	// 	printf("%d|| %s\n", x, e[i++]);
// }

// void	unset_env(char *cmd, t_env *env)
// {
// 	t_env_elem	*elem;

// 	elem = NULL;
// 	if (cmd && !ft_isalpha(cmd[0]))
// 	{
// 		printf("minishell: unset: `%s`: not a valid identifier\n",
// 			cmd);
// 		//status
// 	}
// 	else
// 	{
// 		elem = search_env_elem(env, cmd);
// 		if (elem)
// 			del_env_elem(env, elem);
// 	}
// }

int	unset_builtin(char **cmd, char ***ev)
{
	t_env	*env;
	int		i;

	i = 1;
	env = NULL;
	env = create_env(*ev);
	// while (cmd[i])
	// {
	// 	unset_env(cmd[i], env);
	// 	i++;
	// }
	// *ev = convert_array(env);
	// del_env(env);
	// i = 1;
	// while (env->env[i])
	// 	printf("%s\n", env->env[i++]);
	return (1); //status hnayya succesfully
}
//STATUS needed !

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char **read;
	// int	i;
	
	read = ft_split("unset TMPDIR", ' ');
	// printf("%s\n", read[0]);
	// printf("%s\n", read[1]);
	unset_builtin(read, &env);
	// i = 0;
	// int	index;
	// while(env[i])
	// {
	// 	int	index = strncmp(env[i], cmd, ft_strlen(cmd));
	// 	printf("%d || %d\n", i, index);
	// 	i++;
	// }
}