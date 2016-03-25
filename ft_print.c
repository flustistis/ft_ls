/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:20:21 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/25 19:35:56 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	printloption(data *content)
{
	ft_putchar(content->type);
	ft_putstr(content->permission);
	ft_putstr("  ");
	ft_putnbr(content->linkno);
	ft_putstr("  ");
	ft_putstr(content->useruid);
	ft_putstr("  ");
	ft_putstr(content->groupuid);
	ft_putstr("  ");
	ft_putnbr(content->size);
	ft_putstr("  ");
	ft_putstr(content->date);
	ft_putstr("  ");
	ft_putendl(content->name);
}

static void	redirectfunction(data *content, liste *list)
{
	if (list->option_l)
		printloption(content);
	else
		ft_putendl(content->name);
}

void		print(liste *list)
{
	t_file *tmpfile;

	tmpfile = list->first;
	if(list->option_r == 0)
	{
		redirectfunction(tmpfile->content, list);
		while ((tmpfile = tmpfile->next))
			redirectfunction(tmpfile->content, list);
	}
	else
	{
		while((tmpfile->next))
			tmpfile = tmpfile->next;
		redirectfunction(tmpfile->content, list);
		while((tmpfile = tmpfile->previous))
			redirectfunction(tmpfile->content, list);
	}
}
