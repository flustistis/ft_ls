/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:12:16 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/13 11:42:46 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	printwrite(char **write, t_liste *list)
{
	int			i;
	t_file		*file;
	struct stat	plop;
	char		**dash;

	dash = ft_strstrnew(1);
	!(file = (t_file*)malloc(sizeof(t_file))) ? exit(-1) : NULL;
	!(file->content = (t_data*)malloc(sizeof(t_data))) ? exit(-1) : NULL;
	i = 0;
	while (write[i])
	{
		lstat(write[i], &plop) == -1 ? exit(-1) : NULL;
		file = remplissage(file, plop, list, write[i++]);
		redirectfunction(file->content, list, dash);
		list->option_l ? free(file->content->groupuid) : NULL;
		list->option_l ? free(file->content->useruid) : NULL;
		list->option_l ? free(file->content->permission) : NULL;
		list->option_l || list->option_t ? free(file->content->date) : NULL;
		ft_putstr("free de ");
		ft_putendl(file->content->name);
		free(file->content->name);
	}
	free(file->content);
	free(file);
	free(dash);
}

void		printless(t_data *content, t_liste *list, char *temp)
{
	if (content->type == 'b' || content->type == 'c')
	{
		temp = ft_itoa(content->major);
		printno(temp, list->maxmajorlen + 1);
		free(temp);
		ft_putstr(", ");
		temp = ft_itoa(content->minor);
		printno(temp, list->maxminorlen);
		free(temp);
	}
	else
	{
		temp = ft_itoa(content->size);
		printno(temp, (list->maxsizelen > (list->maxmajorlen +
		list->maxminorlen + 1)) ? list->maxsizelen :
		list->maxmajorlen + list->maxminorlen + 1);
		free(temp);
	}
}

char		*ft_lsargv(char *argv)
{
	if ((argv))
	{
		if (ft_strcmp(argv, ".") == 0)
			return (ft_strdup("./"));
		else if (argv[ft_strlen(argv) - 1] != '/')
			return (ft_strjoin(argv, "/"));
		else
			return (ft_strdup(argv));
	}
	return (ft_strdup("./"));
}

void		test(char **rslt, char **write, char **argv, int *x)
{
	int	i;

	if ((rslt[0]) && (write[0]))
	{
		*x = 1;
	}
	else
		*x = 0;
	i = 0;
	while (write[i])
		free(write[i++]);
	free(write);
	free(argv);
}

char		**traitor(char **argv, t_liste *list, int *x)
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
			if (S_ISDIR(plop.st_mode))
				rslt = ft_strstradd(argv[i], rslt);
			else
				write = ft_strstradd(argv[i], write);
		}
		i++;
	}
	printwrite(write, list);
	test(rslt, write, argv, x);
	return (rslt);
}
