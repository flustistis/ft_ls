/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:13:22 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/15 16:38:48 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

liste	*initlist(liste *list)
{
	list->totalsize = 0;
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->maxgidlen = 0;
	list->maxsizelen = 0;
	return (list);
}

liste *no_option(liste *list)
{
	list->option_l = 0;
	list->option_R = 0;
	list->option_a = 0;
	list->option_r = 0;
	list->option_t = 0;
	return (list);
}

char	**deloptiondup(char **argv, int x)
{
	int i;
	int len;
	char **rslt;

	len = ft_strstrlen(argv);
	i = x;
	while(i < len)
	{
		argv[i - x] = argv[i];
		argv[i] = NULL;
		i++;
	}
	argv[len - x] = NULL;
	if(!(rslt = (char**)malloc(sizeof(char*) * len)))
		return(NULL);
	i = 0;
	while(i < len - x)
	{
		rslt[i] = ft_strdup(argv[i]);
		i++;
	}
	rslt[len - x] = NULL;
	return(rslt);
}


int main(int argc, char **argv)
{
	int x;
	liste	*list;
	int i;
	char **yolo;

	i = 0;
	argv[argc] = NULL;
	list = (liste*)malloc(sizeof(liste));
	list = initlist(list);
	x = 0;
	while(isoption(argv[++i]))
		x++;
	if(x + 1 == argc)
	{
		argv[argc] = ".";
		argv[argc + 1] = NULL;
	}
	if(x > 0)
		list = ft_option(argc, argv);
	else
		list = no_option(list);
	yolo = deloptiondup(argv,x + 1);
	x = 0;
	while (yolo[x] != NULL)
	{
		x != 0 ? ft_putchar('\n') : NULL;
		if(ft_strstrlen(yolo) != 1)
		{
			ft_putstr(yolo[x]);
			ft_putstr(":\n");
		}
		if((list = init(ft_lsargv(yolo[x]), list)) != NULL)
		{
			list = ft_lsttime(list);
			list = ft_lstalpha(list);
			yolo = print(list, yolo);
		}
		else
			exit(-1);
		ft_free(list);
		list = (liste*)malloc(sizeof(liste));
		x++;
	}
	return (0);
}
