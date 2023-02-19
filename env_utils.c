/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:37:22 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/19 16:18:16 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*ft_strndup(char *s1, int n)
{
	char	*copy;
	size_t	s1_len;
	int		i;
	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;
	i = -1;
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	int		i;
	int		j;
	if (!s)
		return (0);
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = start;
	j = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (s[i] && j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}

int	ft_strchr(char *s, int c)
{
	int	i;
	i = 0;
	if (c == '\0')
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;
	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free(s1);
	return (str);
}

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
	if (index != -1)
	{
		key = ft_substr(line, 0, index);
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
	env->head = NULL;
	env->size = 0;
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
