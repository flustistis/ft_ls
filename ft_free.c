/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/11 16:12:26 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int freeMonChainon(t_file *tmpfile)
{

	free(tmpfile->content->name);
	free(tmpfile->content->permission);
	free(tmpfile->content->date);
	free(tmpfile->content->useruid);
	free(tmpfile->content->groupuid);
	free(tmpfile->content);
	return (1);
}

int ft_free(liste *list)
{
	while ((list->first = list->first->next))
	{
		freeMonChainon(list->first);
		free(list->first->previous);
	}
	free(list->first->next);
	free(list->first);
	free(list);
	return (1);
}
