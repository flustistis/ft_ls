/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:24:34 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/04 16:56:09 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *nxtfd(char *str1, char *str2)
{
	char *rslt;
	int i;
	int x;

	x = 0;
	i = 0;
	rslt = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	while(str1[i])
	{
		rslt[i] = str1[i];
		i++;
	}
	if(str1[i - 1] != '/')
		rslt[i] = '/';
	if(str1[i - 1] != '/')
		i++;
	while(str2[x])
	{
		rslt[i] = str2[x];
		x++;
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}



static t_file *initfile(t_file *filetmp, char *argv, liste *list)
{
	DIR *actualdir;
	struct dirent *file;

	if((actualdir = opendir(argv)) == NULL)
	{
		perror("ft_ls :");
		return (NULL);
	}
	while(filetmp && (file = readdir(actualdir)))
		if((list->option_a) || (!list->option_a && file->d_name[0] != '.'))
		{
			if((filetmp->content->name))
				filetmp->next = ft_newfile(argv, file, list);
			else
				filetmp = ft_newfile(argv, file, list);
			if((filetmp->next))
				filetmp->next->previous = filetmp;
			if((filetmp->next))
				filetmp = filetmp->next;
		}
	return (filetmp);
}



liste		*init(char *argv, liste *list)
{
	t_file *filetmp;

	if((filetmp = (t_file*)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if((filetmp->content = (data*)malloc(sizeof(data))) == NULL)
		return (NULL);
	filetmp->content->name = NULL;
	list->initialpath = argv;
	filetmp = initfile(filetmp, argv, list);
	while((filetmp->previous))
		filetmp = filetmp->previous;
	list->first = filetmp;
	return (list);
}
