/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/13 10:34:28 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			free_mon_chainon(t_liste *list, t_file *tmpfile)
{
	free(tmpfile->content->name);
	if (list->option_l)
	{
		free(tmpfile->content->permission);
		free(tmpfile->content->date);
		free(tmpfile->content->groupuid);
	}
	free(tmpfile->content);
	if (tmpfile->next)
		free(tmpfile->previous);
	else
	{
		free(tmpfile->previous);
		free(tmpfile);
	}
	return (1);
}

int			ft_free(t_liste *list)
{
	t_file	*tmpfile;

	if (list->ok == 0)
	{
		return (1);
	}
	tmpfile = list->first;
	while (tmpfile && (tmpfile->next) && free_mon_chainon(list, tmpfile))
	{
		tmpfile = tmpfile->next;
	}
	(tmpfile) ? free_mon_chainon(list, tmpfile) : 0;
	if (closedir(list->actualdir) == -1)
		exit(-1);
	list->maxsizelen = 0;
	free(list->initialpath);
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->totalsize = 0;
	list->maxgidlen = 0;
	return (1);
}

static int	teststrstralpha(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

char		**ft_strstralpha(char **argv)
{
	char	*temp;
	size_t	i;

	while (teststrstralpha(argv) == 0)
	{
		i = 0;
		while (argv[i])
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
		}
	}
	return (argv);
}

t_file		*remplissage(t_file *rslt, struct stat plop, t_liste *list,
				char name[256])
{
	rslt->content->name = ft_strnew(ft_strlen(name));
	rslt->content->name = ft_strcpy(rslt->content->name, name);
	if ((list->option_l) || (list->option_t))
	{
		name = ctime(&plop.st_mtime);
		rslt->content->date = ft_timels(ctime(&plop.st_mtime));
		rslt->content->time = plop.st_mtime;
	}
	if ((list->option_l) || (list->option_gr))
		rslt->content->type = ft_type(plop);
	rslt = remplissageforl(rslt, list, plop);
	rslt->next = NULL;
	rslt->previous = NULL;
	return (rslt);
}
