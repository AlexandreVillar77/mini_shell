/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:11:09 by avillar           #+#    #+#             */
/*   Updated: 2022/06/20 15:37:29 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_echo0(t_arg *arg, int n)
{
	t_arg	*tmp;

	tmp = arg;
	while (tmp)
	{
		write(1, tmp->arg, ft_strlen(tmp->arg));
		if (tmp->next_arg)
			write(1, " ", 1);
		tmp = tmp->next_arg;
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}

int	args_size(t_arg *arg)
{
	int		size;
	t_arg	*tmp;

	size = 0;
	tmp = arg;
	while (tmp)
	{
		if (tmp->nbr < 0)
			break ;
		size += ft_strlen(tmp->arg);
		tmp = tmp->next_arg;
	}
	return (size);
}

int	print_echo_fd(t_arg *arg, char *filename, int n, int red)
{
	char	*content;

	content = malloc(sizeof(char) * (args_size(arg)));
	if (!content)
		exit (1);
	while (arg)
	{
		if (arg->nbr < 0)
			break ;
		content = ft_strjoin(content, arg->arg);
		if (arg->next_arg)
			content = ft_strjoin(content, " ");
		arg = arg->next_arg;
	}
	if (red == -1)
		ft_redirection(content, filename);
	else if (red == -2)
		ft_redirection_appen(content, filename);
	if (n == 0)
		write (1, "\n", 1);
	return (0);
}

int	ft_echo(t_cmd *cmd)
{
	int		fd;
	int		n;
	t_arg	*arg;
	t_arg	*filename;

	fd = 0;
	n = 0;
	/*arg = malloc(sizeof(t_arg *));
	if (!arg)
		exit (1);*/
	arg = cmd->next_arg;
	filename = cmd->next_arg;
	if (ft_strncmp(arg->arg, "-n", 2) == 0)
	{
		arg = arg->next_arg;
		n = 1;
	}
	if (check_redir(arg) < 0)
	{
		fd = check_redir(arg);
		while (filename->nbr > 0)
			filename = filename->next_arg;
		filename = filename->next_arg;
	}
	if (fd < 0)
		print_echo_fd(arg, filename->arg, n, fd);
	else 
		print_echo0(arg, n);
	return (0);
}