/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/03 16:23:35 by gmorer           ###   ########.fr       */
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

static int		teststrstralpha(char **argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

char	**ft_strstralpha(char **argv)
{
	char *temp;
	size_t i;

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
