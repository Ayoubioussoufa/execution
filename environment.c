/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:11:51 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/17 09:11:51 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	del_env_elem(t_env *env, t_env_elem *elem)
{
	if (elem && elem->next)
		elem->next->prev = elem->prev;
	if (elem && elem->prev)
		elem->prev->next = elem->next;
	printf("b %s\n", elem->key);
	free(elem->key);
	printf("a %s\n", elem->key);
	printf("b %s\n", elem->value);
	free(elem->value);
	printf("a %s\n", elem->value);
	free(elem);
	printf("after free %s %s|\n", elem->key, elem->value);
	env->size--;
	elem = NULL;
	printf("**********************\n");
	// int	i = 0;
	// while (env->env[i])
	// 	printf("%s\n", env->env[i++]);
}

t_env_elem	*search_env_elem(t_env *env, char *key)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp && strcmp(tmp->key, key))
	{
		// printf("%s\n", key);
		// printf("%s\n", tmp->key);
		tmp = tmp->next;
	}
	// printf("%s\n", key);
	// printf("%s\n", tmp->key);
	return (tmp);
}

void	print_env(t_env *env)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	del_env(t_env *env)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = tmp->next;
	}
	free(env);
	// int i = 0;
	// while (env->env[i])
	// 	printf("%s\n", env->env[i++]);
}

char	**convert_array(t_env *env)
{
	t_env_elem	*tmp;
	char		**arr;
	int			i;

	i = 0;
	tmp = env->head;
	arr = malloc((env->size + 1) * sizeof(char *));
	if (arr)
	{
		while (i < env->size)
		{
			arr[i] = ft_strdup(tmp->key);
			if (tmp->value)
			{
				arr[i] = ft_strjoin(arr[i], "=");
				arr[i] = ft_strjoin(arr[i], tmp->value);
			}
			tmp = tmp->next;
			i++;
		}
		arr[i] = NULL;
	}
	// i = 0;
	// while (arr[i])
	// 	printf("%s\n", arr[i++]);
	return (arr);
}
