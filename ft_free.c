/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/03 16:20:36 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int freeMonChainon(t_liste *list, t_file *tmpfile)
{
	if(!(tmpfile->next))
		return (0);
	if (list->option_l)
	{
		free(tmpfile->content->permission);
		free(tmpfile->content->date);
	}
	free(tmpfile->content->name);
	free(tmpfile->content);
	return (1);
}

int ft_free(t_liste *list)
{
	t_file	*tmpfile;

	if(list->ok == 0)
		return(1);
	tmpfile = list->first;
	while ((tmpfile->next) && freeMonChainon(list, tmpfile))
	{
		free(tmpfile->previous);
		tmpfile = tmpfile->next;
	}
	free(tmpfile->next);
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
