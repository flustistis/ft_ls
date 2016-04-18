/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/18 12:05:24 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int freeMonChainon(liste *list, t_file *tmpfile)
{
	if(!(tmpfile->next))
		return (0);
	if (list->option_l)
	{
		free(tmpfile->content->permission);
		free(tmpfile->content->date);
	}
	free(tmpfile->content);
	return (1);
}

int ft_free(liste *list)
{
	t_file	*tmpfile;

	tmpfile = list->first;
	while ((tmpfile->next) && freeMonChainon(list, tmpfile))
	{
		free(tmpfile->previous);
		tmpfile = tmpfile->next;
	}
	//free(list->initialpath);
	list->initialpath = NULL;
	free(tmpfile->next);
	list->maxsizelen = 0;
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->totalsize = 0;
	list->maxgidlen = 0;
	return (1);
}
