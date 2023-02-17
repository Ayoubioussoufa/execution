/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:12:51 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/12 18:12:51 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
	{
		printf("0");
		return ;
	}
	// printf("%s\n", s);
	// while (1)
	// if (!strcmp(s, "(null)"))
	// 	ft_putchar('0');
	len = ft_strlen(s);
	while (i < len)
		write(1, &s[i++], 1);
}

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	if (n < 0)
	{
		// if (!strcmp(str, "(null)"))
		// 	ft_putchar('0');
		while (str[++i] && i < (int)ft_strlen(str) + n)
			ft_putchar(str[i]);
	}
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

void	echo(char **str, int pos)
{
	int		start;
	int		end;
	int		strl;

	start = is_quote(str[pos][0]);
	strl = ft_strlen(str[pos]);
	end = is_quote(str[pos][strl - 1]);
	if (end && start)
		ft_putnstr(str[pos] + 1, -1);
	else if (end)
		ft_putnstr(str[pos], -1);
	else if (start)
		ft_putstr(str[pos] + 1);
	else
		ft_putstr(str[pos]);
	ft_putchar(' ');
}

void	echo_last(char **str, int pos)
{
	int		start;
	int		end;
	int		strl;

	start = is_quote(str[pos][0]);
	strl = ft_strlen(str[pos]);
	end = is_quote(str[pos][strl - 1]);
	if (end && start)
		ft_putnstr(str[pos] + 1, -1);
	else if (end)
		ft_putnstr(str[pos], -1);
	else if (start)
		ft_putstr(str[pos] + 1);
	else
		ft_putstr(str[pos]);
}

int	echo_builtin(char **cmd)
{
	int	j = 0;
	int	f = 0;
	int	i = 1;

	if (!cmd[1])
	{
		write(1, "\n", 1);
		return (1);
	}
	else if (cmd[1][0] == '-' && cmd[1][1] == 'n')
	{
		while (cmd[1][i])
		{
			if (cmd[1][i] == 'n')
				f = 1;
			else
			{
				f = 0;
				break ;
			}
			i++;
		}
	}
	// printf("%d\n", f);
	if (f)
		j++;
	// printf("%d\n", j);
	// while (1)
	while (cmd[++j])
	{
		// printf("%s\n", cmd[j]);
		// while (1)
		if (cmd[j + 1])
			echo(cmd, j);
		else
			echo_last(cmd, j);
		if (!cmd[j + 1] && f)
			ft_putchar('\n');
		else if (!cmd[j + 1] && !f)
			ft_putchar('\0');
	}
	return (1);
}

int	main()
{
	char **cmd;
	char	**lol;

	// cmd = ft_split("echo \"\\0\"", ' ');
	cmd = ft_split("echo -n 0", ' ');
	// lol = ft_split("echo \0", ' ');
	// printf("%s %s %s \n", cmd[0], cmd[1], cmd[2]);
	// printf("%s %s \t \n", lol[0], lol[1]);
	echo_builtin(cmd);
	// printf("%s\n", cmd[1]);
	// ft_putchar("\\0\n");
	// printf("\\0\n");
	// printf("%d\n", strlen("0"));
	// printf("%s\n", cmd[0]);
	// printf("%s\n", cmd[1]);
	// printf("%s\n", cmd[2]);
}

/* 
bash-3.2$ echo \0
0
bash-3.2$ echo '\0' DONE
\0
bash-3.2$ echo "\0" DONE
\0
bash-3.2$ echo 0 DONE
0
*/