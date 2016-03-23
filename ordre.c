/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/23 13:41:27 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int testalpha(liste *list)
{
	t_file *tmpfile;

	tmpfile = list->first;
	while((tmpfile->next))
	{
		if (ft_strcmp(tmpfile->content->name, tmpfile->next->content->name) > 0)
			return (0);
		tmpfile = tmpfile->next;
	}
	return (1);
}

static int testtime(liste *list)
{
	t_file *tmpfile;

	tmpfile = list->first;
	while((tmpfile->next))
	{
		if(tmpfile->content->time < tmpfile->next->content->time)
			return(0);
		tmpfile = tmpfile->next;
	}
	return (1);
}

liste	*ft_lstalpha(liste *list)
{
	data *tmpdata;;
	t_file *tmpfile;

	if((list->option_t))
		return(list);
	while(!(testalpha(list)))
	{
		tmpfile = list->first;
		while((tmpfile->next))
		{
			if (ft_strcmp(tmpfile->content->name, tmpfile->next->content->name) > 0)
			{
				tmpdata = tmpfile->content;
				tmpfile->content = tmpfile->next->content;
				tmpfile->next->content = tmpdata;
			}
			tmpfile = tmpfile->next;
		}
	}
	return (list);
}

liste	*ft_lsttime(liste *list)
{
	data	*tmpdata;
	t_file	*tmpfile;

	if (!(list->option_t))
		return (list);
	while(!(testtime(list)))
	{
		tmpfile = list->first;
		while((tmpfile->next))
		{
			if(tmpfile->content->time < tmpfile->next->content->time)
			{
				tmpdata = tmpfile->content;
				tmpfile->content = tmpfile->next->content;
				tmpfile->next->content = tmpdata;
			}
			tmpfile = tmpfile->next;
		}
	}
	return (list);
}
