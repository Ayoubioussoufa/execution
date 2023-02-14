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
		return ;
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
		while (str[++i] && i < (int)ft_strlen(str) + n)
			ft_putchar(str[i]);
	}
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}

int    is_quote(char c)
{
    return (c == '"' || c == '\'');
}

void    echo(char **str, int pos)
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

    if (!cmd[1])
    {
        write(1, "\n", 1);
        return (1);
    }
    else if (cmd[1][0] == '-' && cmd[1][1] == 'n' /*&& cmd[1][2] == '\0'*/)
        f = 1;
	if (f)
		++j;
    while (cmd[++j])
    {
		echo(cmd, j);
		if (!cmd[j + 1] && f)
			ft_putchar('\0');
		else if (!cmd[j + 1] && !f)
			ft_putchar('\n');
	}
    return (1);
}

int	main()
{
	char **cmd;

	cmd = ft_split("echo \"-nlwkfm Hello\"", ' ');
	echo_builtin(cmd);
	// printf("%s\n", cmd[0]);
	// printf("%s\n", cmd[1]);
	// printf("%s\n", cmd[2]);
}