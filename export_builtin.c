/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:40:06 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/20 17:09:00 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mini_shell.h"

// int	export_builtin(char **cmd)
// {
	//khass n initializi env in main and start using it everywhere it needs to be;
    //env init and creat
    //then in unset, i give it that struct olkhdma at3awd mmn lwl OR w9tma nssali ghadi nfreei on3mr struct b akhir env dyali, that might be a good idea
    // f export anchd ayi variable tcreat + aykoun dakchi msorti b ordre alphabetique bl env
    // f env ila kant chi haja bla = maghatktbch wlk
    // li fiha = bo7dha, f export katktb x="" , env katktb ghir x=
    // declare -x in bash f lwl dyal ayi jomla f export.
// }
//les cas li f export :
//export bo7dha
//export b variable deja kayna  || makaynach
//variable fiha = wla la ""flag""
//export b vraiable makayna
// export katdefini variable b = dyalha

//environment khdam fih f cd, unset, export !!!!!!! needs to be changed there

void	ft_swap(t_env_elem *a, t_env_elem *b)
{
	char	*key_tmp;
	char	*val_tmp;

	key_tmp = a->key;
	val_tmp = a->value;
	a->key = b->key;
	a->value = b->value;
	b->key = key_tmp;
	b->value = val_tmp;
}

void	ft_sort(t_env *env)
{
	t_env_elem	*current;

	current = env->head;
	while (current->next)
	{
		if (ft_strcmp(current->key, current->next->key) > 0)
		{
			ft_swap(current, current->next);
			current = env->head;
		}
		else
			current = current->next;
	}
}

void	print_sorted_env(t_env *env)
{
	t_env		*tmp;
	t_env_elem	*current;

	tmp = env;
	ft_sort(tmp);
	current = tmp->head;
	while (current)
	{
		printf("declare -x %s", current->key);
		if (current->value)
			printf("=\"%s\"", current->value);
		else
			printf("=\'\'"); 
		printf("\n");
		current = current->next;
	}
}

int	search_env_elemindex(t_env *env, char *key)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp && strcmp(tmp->key, key))
		tmp = tmp->next;
	if (tmp && !strcmp(tmp->key, key))
		return (1);
	return (0);
}

void	modify_env(t_env *env, t_env_elem *new, char *cmd)
{
	del_env_elem(env, new);
	int	i = 0;
	while (env->env[i])
		printf("%s\n", env->env[i++]);
	// new = new_env_elem(cmd);
	// add_env_elem(env, new);
}

void	add_env_elemb(t_env *env, t_env_elem *new)
{
	t_env_elem	*tmp;

	tmp = env->head;
	if (!env->head)
		env->head = new;
	else
	{
		while (tmp->next->next)
			tmp = tmp->next;
		env->size++;
		tmp->next = new;
		new->prev = tmp;
		// new->next = tmp->next->next;
		printf("%s %s\n", new->key, new->value);
	}
	int	i = 0;
	while (env->env[i])
		printf("%s\n", env->env[i++]);
	new = new_env_elem(cmd);
	search_env_elem(env, new->key);
	add_env_elem(env, new);
	// int i = 0;
	// while (env->env[i])
	// 	printf("%s\n", env->env[i++]);
	// printf("%s=%s\n", new->key, new->value);
}

void	add_var(t_env *env, char *cmd)
{
	t_env_elem	*new;
	t_env_elem	*newl;
	int	i;

	new = NULL;
	newl = NULL;
	newl = new_env_elem(cmd);
	new = search_env_elem(env, newl->key);
	// printf("%s %s\n", newl->key, newl->value);
	if (new)
	{
		free(new->value);
		new->value = newl->value;
	}
	else
	{
		newl->key = ft_strjoin(newl->key, "=");
		newl->key = ft_strjoin(newl->key, newl->value);
		free(newl->value);
		newl->value = NULL;
		add_env_elemb(env, newl);
		// printf("%s\n", newl->key);
	}
	// printf("key: %s %s\n", new->key, new->value);
	// newl = search_env_elem(env, new->key);
	// printf("%p\n", newl);
	// if (newl)
	// {
	// 	del_env_elem(env, new);
	// 	// newl = new_env_elem(cmd);
	// 	// printf("%s=%s\n **************\n", newl->key, newl->value);
	// 	// add_env_elem(env, newl);
	// }
}

//ila kant fih  = rah ayt7 fl environment 

int	export_builtin(char ***ev, char **cmd)
{
	t_env	*env;
	int	i;

	i = 1;
	env = NULL;
	env = create_env(*ev);
	if (!cmd[i])
	printf("*************************\n");
	if (!cmd[1])
		print_sorted_env(env);
	else
	{
		while (cmd[i])
		{
			if (!ft_isalpha(cmd[i][0]))
				return (ft_puterr(cmd[0],
					cmd[i], "not a valid identifier", EXIT_FAILURE));
			add_var(env, cmd[i]);
			i++;
		}
		*ev = convert_array(env);
	}
	i = 0;
	// while (env->env[i])
	// 	printf("%s\n", env->env[i++]);
	*ev = convert_array(env);
	del_env(env);
	// status = EXIT_SUCCESS;
	// return (EXIT_SUCCESS);
    return (1);
}

int	main(int ac, char **av, char **env)
{
	char	**cmd;
	char	**cmdd;
	int	i;

	i = 0;
	cmd = ft_split("export erf=wrfwrf", ' ');
	cmdd = ft_split("export", ' ');
	cmd = ft_split("export", ' ');
	export_builtin(&env, cmd);
	// while (env[i])
	// 	printf("%s\n", env[i++]);
	// export_builtin(&env, cmdd);
	// system("leaks a.out");
}