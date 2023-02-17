/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:37:22 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/17 16:37:36 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_env_elem	*new_env_elem(char *line)
{
	t_env_elem	*elem;
	char		*key;
	char		*value;
	unsigned int	index;

	index = ft_strchr(line, '=');
	elem = malloc(sizeof(t_env_elem));
	elem->next = NULL;
	elem->prev = NULL;
	if (!elem)
	{
    	free(elem);
    	return (NULL);
	}
	if (index)
	{
		key = ft_substr(line, 0, index + 1);
		value = ft_substr(line, index + 1, ft_strlen(line) - index);
		if (!key || !value)
			return (NULL);
		elem->key = key;
		elem->value = value;
	}
	else
	{
		elem->key = ft_strdup(line);
		elem->value = NULL;
	}
	return (elem);
}

void	add_env_elem(t_env *env, t_env_elem *new)
{
	t_env_elem	*tmp;

	tmp = env->head;
	if (!env->head)
		env->head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		env->size++;
	}
}

t_env	*init_env(t_env *env)
{
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	return (env);
}

t_env	*create_env(char **tab)
{
	t_env	*env;
	int		i;	

	env = NULL;
	env = init_env(env);
	env->env = tab;
	i = 0;
	while (tab[i])
		add_env_elem(env, new_env_elem(tab[i++]));
	return (env);
}
