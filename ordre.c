/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/02 17:00:04 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int testalpha(t_liste *list)
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

static int testtime(t_liste *list)
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

t_liste	*ft_lstalpha(t_liste *list)
{
	t_data *tmpdata;;
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

t_liste	*ft_lsttime(t_liste *list)
{
	t_data	*tmpdata;
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
