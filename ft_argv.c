/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:12:16 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/04 15:44:51 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printwrite(char **write, t_liste *list)
{
	int		i;
	t_file	*file;
	struct stat plop;
	char **dash;

	dash = ft_strstrnew(1);
	if (!(file = (t_file*)malloc(sizeof(t_file))) || !(file->content = (t_data*)malloc(sizeof(t_data))))
		exit(-1);
	i = 0;
	while (write[i])
	{
		if (lstat(write[i], &plop) == -1)
			exit(-1);
		file = remplissage(file, plop, list, write[i]);
		redirectfunction(file->content, list, dash);
		freeMonChainon(list, file);
		i++;
	}
	free(dash);
}

char	*ft_lsargv(char *argv)
{
	if ((argv))
	{
		if (ft_strcmp(argv,".") == 0)
			return ("./");
		else if (argv[ft_strlen(argv) - 1] != '/')
			return(strcatturfu(argv, "/"));
		else
			return (argv);
	}
	return ("./");
}

char	**traitor(char **argv, t_liste *list)
{
	char		**rslt;
	size_t		i;
	struct stat	plop;
	char		**write;

	argv = ft_strstralpha(argv);
	rslt = ft_strstrnew(0);
	write = ft_strstrnew(0);
	i = 0;
	while (i < ft_strstrlen(argv))
	{
		if (lstat(argv[i], &plop) == -1)
			perror(ft_strjoin("ft_ls: ", argv[i]));
		else
		{
			if(S_ISDIR(plop.st_mode))
				rslt = ft_strstradd(argv[i], rslt);
			else
				write = ft_strstradd(argv[i], write);
		}
		i++;
	}
	printwrite(write, list);
	if ((rslt[0]) && (write[0]))
	{
		ft_putchar('\n');
		ft_putstr(rslt[0]);
		ft_putstr(":\n");
	}
	return (rslt);
}
