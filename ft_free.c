/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:37:46 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/22 17:31:18 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int freeMonChainon(liste *list, t_file *tmpfile)
{
	if(!(tmpfile->next))
		return (0);
	printf("tmpfile->content->name exist\n");
	free(tmpfile->content->name);
	printf("ok pour le free de content->name\n");
	if (list->option_l)
	{
		free(tmpfile->content->permission);
		free(tmpfile->content->date);
		free(tmpfile->content->useruid);
		free(tmpfile->content->groupuid);
	}
	printf("free de tmpfile->content\n");
	free(tmpfile->content);
	printf("return 1 in ft in free.c\n");
	return (1);
}

int ft_free(liste *list)
{
	while (((list->first = list->first->next)) && freeMonChainon(list, list->first))
		free(list->first->previous);
	free(list->first->next);
	free(list->first);
	free(list);
	return (1);
}
