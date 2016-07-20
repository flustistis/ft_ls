/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/07/20 16:29:11 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printno(char *str, size_t max)
{
	while (ft_strlen(str) < max)
	{
		max--;
		ft_putchar(' ');
	}
	ft_putstr(str);
}

static void	printstr(char *str, size_t max)
{
	ft_putstr(str);
	while (ft_strlen(str) < max)
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
	printless(content, list, temp);
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

char		**redirectfunction(t_data *content, t_liste *list, char **add)
{
	char	*temp;

	if (list->option_gr)
		if (content->type == 'd' && ft_strcmp(content->name, ".") != 0 &&
				ft_strcmp(content->name, "..") != 0)
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
	t_file	*file;

	if ((file = list->first) && !file)
		list->option_l == 1 ? ft_putendl("total 0") : NULL;
	if ((rslt = ft_strstrnew(1)) && !file)
	{
		free(rslt);
		return (ft_strstrdelfirst(yolo));
	}
	list->option_l == 1 ? ft_putstr("total ") : NULL;
	list->option_l == 1 ? ft_putnbr(list->totalsize) : NULL;
	list->option_l == 1 ? ft_putchar('\n') : NULL;
	if (!list->option_r && (rslt = redirectfunction(file->content, list, rslt)))
		while ((file = file->next))
			rslt = redirectfunction(file->content, list, rslt);
	else
	{
		while ((file->next))
			file = file->next;
		rslt = redirectfunction(file->content, list, rslt);
		while ((file = file->previous))
			rslt = redirectfunction(file->content, list, rslt);
	}
	if (list->option_gr == 1 && rslt[0] != NULL)
		return (ft_strstrjoin(rslt, ft_strstrdelfirst(yolo)));
	free(rslt);
	return (ft_strstrdelfirst(yolo));
}
