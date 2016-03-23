/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/23 15:53:48 by gmorer           ###   ########.fr       */
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
	free(tmpfile->next);
	free(list);
	return (1);
}
