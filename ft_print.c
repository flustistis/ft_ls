/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/15 17:43:24 by gmorer           ###   ########.fr       */
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

static void	redirectfunction(data *content, liste *list)
{
	if (list->option_l)
		printloption(content, list);
	else
		ft_putendl(content->name);
}

char		**print(liste *list, char **yolo)
{
	char	**rslt;
	t_file	*tmpfile;

	if(!(rslt = (char**)malloc(sizeof(char*))))
		exit(-1);
	rslt[0] = NULL;
	tmpfile = list->first;
	if ((list->option_l))
	{
		ft_putstr("total ");
		ft_putnbr(list->totalsize / 512);
		ft_putchar('\n');
	}
	if (list->option_r == 0)
	{
		redirectfunction(tmpfile->content, list);
		if (list->option_r == 0)
			while ((tmpfile = tmpfile->next))
				redirectfunction(tmpfile->content, list);
		else
		{
			while ((tmpfile->next))
				tmpfile = tmpfile->next;
			redirectfunction(tmpfile->content, list);
			while ((tmpfile = tmpfile->previous))
				redirectfunction(tmpfile->content, list);
		}
	}
	return (rslt);
}
