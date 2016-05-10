/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/10 15:58:04 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int freeMonChainon(t_liste *list, t_file *tmpfile)
{
	free(tmpfile->content->name);
	if(!(tmpfile->next))
		return (0);
	if (list->option_l)
	{
		free(tmpfile->content->permission);
		free(tmpfile->content->date);
		free(tmpfile->content->groupuid);
	}
	free(tmpfile->content->name);
	free(tmpfile->content);
	free(tmpfile->previous);
	return (1);
}

int ft_free(t_liste *list)
{
	t_file	*tmpfile;

	if(list->ok == 0)
		return(1);
	tmpfile = list->first;
	while (tmpfile && (tmpfile->next) && freeMonChainon(list, tmpfile))
	{
		tmpfile = tmpfile->next;
	}
	(tmpfile) ? freeMonChainon(list, tmpfile) : 0;
	if(closedir(list->actualdir) == -1)
		exit(-1);
	list->maxsizelen = 0;
	list->initialpath = NULL;
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->totalsize = 0;
	list->maxgidlen = 0;
	return (1);
}
