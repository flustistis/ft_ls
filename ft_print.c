/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/18 12:09:48 by gmorer           ###   ########.fr       */
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

static void	printloption(data *content, liste *list)
{
	ft_putchar(content->type);
	ft_putstr(content->permission);
	ft_putstr("  ");
	printno(ft_itoa(content->linkno), list->maxlinklen);
	ft_putstr(" ");
	printstr(content->useruid, list->maxuidlen);
	ft_putstr("  ");
	printstr(content->groupuid, list->maxgidlen);
	ft_putstr("  ");
	printno(ft_itoa(content->size), list->maxsizelen);
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

static char	**redirectfunction(data *content, liste *list, char **add)
{
	if (list->option_R)
		if(content->type == 'd' && ft_strcmp(content->name, ".") != 0 && ft_strcmp(content->name, "..") != 0)
			add = ft_strstradd(nxtfd(list->initialpath,content->name), add);
	if (list->option_l)
		printloption(content, list);
	else
		ft_putendl(content->name);
	return (add);
}

char		**print(liste *list, char **yolo)
{
	char	**rslt;
	t_file	*tmpfile;

	rslt = ft_strstrnew(1);
	tmpfile = list->first;
	if ((list->option_l))
	{
		ft_putstr("total ");
		ft_putnbr(list->totalsize / 512);
		ft_putchar('\n');
	}
	if (list->option_r == 0)
	{
		rslt = redirectfunction(tmpfile->content, list, rslt);
		if (list->option_r == 0)
			while ((tmpfile = tmpfile->next))
				rslt = redirectfunction(tmpfile->content, list, rslt);
		else
		{
			while ((tmpfile->next))
				tmpfile = tmpfile->next;
			rslt = redirectfunction(tmpfile->content, list, rslt);
			while ((tmpfile = tmpfile->previous))
				rslt = redirectfunction(tmpfile->content, list, rslt);
		}
	}
	if(list->option_R == 1 && rslt[0] != NULL)
		return (ft_strstrjoin(rslt, ft_strstrdelfirst(yolo)));
	else
		return (ft_strstrdelfirst(yolo));
}
