/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:13:14 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/13 13:33:47 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

//search path
//OLDPWD \\ PWD

char	*ft_strdup(const char *source)
{
	char	*mem;
	int		i;

	i = 0;
	mem = malloc((ft_strlen(source) + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	while (source[i] != '\0')
	{
		mem[i] = source[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	lengthstring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	lengthstring = ft_strlen(s);
	if (!s[0] || start >= lengthstring || len == 0)
		return (ft_strdup(""));
	if (len > (lengthstring - start))
		len = lengthstring - start;
	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	while (len > i && s[start] != '\0')
		mem[i++] = s[start++];
	mem[i] = '\0';
	return (mem);
}


int	check(char const *set, char s)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrimbehind(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*mem;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[len] && s1[len] != '/')
		len--;
	mem = ft_substr(s1, i, len - i);
	return (mem);
}

char	**get_pathcd(char **env, int index)
{
	char	**paths;
	char	*cmd;
	int		i;

	i = 0;
	while (env[i])
	{
		if (index == 0)
		{
			if (ft_strnstr(env[i], "OLDPWD", 7))
			{
				paths = ft_split(env[i] + 7, ':');
			// if (!paths)
				// error("Split function failed", 1);
				return (paths);
			}
			i++;
		}
		else if (index == 1)
		{
			if (ft_strnstr(env[i], "HOME", 4))
			{
				paths = ft_split(env[i] + 5, ':');
			// if (!paths)
				// error("Split function failed", 1);
				return (paths);
			}
			i++;
		}
		// else if (index == 2)
		// {
		// 	if (ft_strnstr(env[i], "PWD", 3))
		// 	{
		// 		paths = ft_split(env[i] + 4, ':');
		// 		// printf("%s\n", paths[0]);
		// 		cmd = ft_strtrimbehind(paths[0], "/");
		// 		// printf("%s\n", cmd);
		// 		// printf("whatever\n");
		// 		// while(1);
		// 	// // if (!paths)
		// 	// 	// error("Split function failed", 1);
		// 		return (&cmd);
		// 	}
		// 	i++;
		// }
	}
	return (paths);
}

int cd_builtin(char **env, char **cmd)
{
	char	**path;
	char	*cmds;
	char	*command;
	char	get[256];
	int	i;

	i = 0;
	if (!strcmp(cmd[0], "cd") && !cmd[1])
	{
		path = get_pathcd(env, 1);
		printf("%s\n", path[0]);
		printf("%s\n", path[1]);
		i = chdir(*path);
		printf("i : %d\n", i);
	}
	else if (cmd[2])
		exit(1);
	else if (!strcmp(cmd[1], "-"))
	{
		path = get_pathcd(env, 0);
		printf("%s\n", path[0]);
		i = chdir(*path);
		printf("%s\n", path[1]);
		printf("i : %d\n", i);
	}
	else if (!strcmp(cmd[1], ".."))
	{
		getcwd(get, sizeof(get));
		cmds = ft_strtrimbehind(get, "/");
		printf("%s\n", cmds);
		i = chdir(*cmd);
		printf("i : %d\n", i);
	}
	else if (!strcmp(cmd[1], "."))
	{
		getcwd(get, sizeof(get));
		printf("%s\n", get);
	}
	else
	{
		getcwd(get, sizeof(get));
		printf("%s\n", get);
		printf("%c\n", cmd[1][0]);
		if (strcmp(cmd[1], "/"))
		{
			command = ft_strjoin(get, "/");
			cmds = ft_strjoin(command, cmd[1]);
		}
		else
			cmds = ft_strjoin(get, cmd[1]);
		printf("%s\n", cmds);
		if (access(cmds, F_OK) == 0)
		{
			if (access(cmds, R_OK))
				exit(1);//error
			else if (access(cmds, W_OK))
				exit(1);//error
			else if (access(cmds, X_OK))
				exit(1);//error
		}
		else
			exit(1);//error
		i = chdir(cmds);
		printf("why\n");
		printf("i : %d\n", i);
	}
	printf("why\n");
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char	cmds[256];
	char	**cmd;

	cmd = ft_split("cd", ' ');
	cd_builtin(env, cmd);
	// printf("why\n");
	// while(1);
	// getcwd(cmds, sizeof(cmds));
	// cmd = ft_strtrimbehind(cmds, "/");
	// printf("%s\n", cmd);
	// chdir(cmd);
	// int i = chdir("cd ..");
	// printf("%d\n", i);	
	// while(1);
	// printf("working directory : %s\n", cmds);
}