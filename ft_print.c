/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/11 12:15:12 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	printno(char *str, size_t max)
{
	while(ft_strlen(str) < max)
	{
		max--;
		ft_putchar(' ');
	}
		ft_putstr(str);
}

static void	printstr(char *str, size_t max)
{
	ft_putstr(str);
	while(ft_strlen(str) < max)
	{
		ft_putchar(' ');
		max--;
	}
}

static void	printloption(t_data *content, t_liste *list)
{
	char *temp;

	ft_putchar(content->type);
	ft_putstr(content->permission);
	ft_putstr("  ");
	temp = ft_itoa(content->linkno);
	printno(temp, list->maxlinklen);
	free(temp);
	ft_putstr(" ");
	printstr(content->useruid, list->maxuidlen);
	ft_putstr("  ");
	printstr(content->groupuid, list->maxgidlen);
	ft_putstr("  ");
	if (content->type == 'b' || content->type == 'c')
	{
		temp = ft_itoa(content->major);
		printno(temp, list->maxmajorlen + 1);
		free(temp);
		ft_putstr(", ");
		temp = ft_itoa(content->minor);
		printno(temp, list->maxminorlen);
		free(temp);
	}
	else
	{
		temp = ft_itoa(content->size);
		printno(temp, (list->maxsizelen > (list->maxmajorlen + list->maxminorlen + 1)) ? 
				list->maxsizelen : list->maxmajorlen + list->maxminorlen + 1);
		free(temp);
	}
	ft_putstr(" ");
	ft_putstr(content->date);
	ft_putstr(" ");
	ft_putstr(content->name);
	if (content->type == 'l')
		ft_putstr(" -> ");
	if (content->type == 'l')
		ft_putstr(content->linkto);
	ft_putchar('\n');
}

char	**redirectfunction(t_data *content, t_liste *list, char **add)
{
	char	*temp;
	if (list->option_gr)
		if(content->type == 'd' && ft_strcmp(content->name, ".") != 0 && ft_strcmp(content->name, "..") != 0)
		{
			temp = nxtfd(list->initialpath, content->name);
			add = ft_strstradd(ft_strdup(temp), add);
			free(temp);
		}
	if (list->option_l)
		printloption(content, list);
	else
		ft_putendl(content->name);
	return (add);
}

char		**print(t_liste *list, char **yolo)
{
	char	**rslt;
	t_file	*tmpfile;

	rslt = ft_strstrnew(1);
	tmpfile = list->first;
	if(!tmpfile)
	{
		if (list->option_l)
			ft_putendl("total 0");
		return(ft_strstrdelfirst(yolo));
	}
	if ((list->option_l))
	{
		ft_putstr("total ");
		ft_putnbr(list->totalsize);
		ft_putchar('\n');
	}
	if (list->option_r == 0)
	{
		rslt = redirectfunction(tmpfile->content, list, rslt);
		if (list->option_r == 0)
			while ((tmpfile = tmpfile->next))
				rslt = redirectfunction(tmpfile->content, list, rslt);
	}
	else
	{
		while ((tmpfile->next))
			tmpfile = tmpfile->next;
		rslt = redirectfunction(tmpfile->content, list, rslt);
		while ((tmpfile = tmpfile->previous))
			rslt = redirectfunction(tmpfile->content, list, rslt);
	}
	if(list->option_gr == 1 && rslt[0] != NULL)
		return (ft_strstrjoin(rslt, ft_strstrdelfirst(yolo)));
	else
		free(rslt);
		return (ft_strstrdelfirst(yolo));
}
