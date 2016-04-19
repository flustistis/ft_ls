/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:13:22 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/18 11:57:16 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static liste	*initlist(liste *list)
{
	list->totalsize = 0;
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->maxgidlen = 0;
	list->maxsizelen = 0;
	return (list);
}

static liste *no_option(liste *list)
{
	list->option_l = 0;
	list->option_R = 0;
	list->option_a = 0;
	list->option_r = 0;
	list->option_t = 0;
	return (list);
}

static char	**deloptiondup(char **argv, int x)
{
	size_t	i;
	size_t	len;
	char	**rslt;

	len = ft_strstrlen(argv);
	i = (size_t)x;
	while(i < len)
	{
		argv[(int)i - x] = argv[i];
		argv[i] = NULL;
		i++;
	}
	argv[(int)len - x] = NULL;
	if(!(rslt = (char**)malloc(sizeof(char*) * len)))
		return(NULL);
	i = 0;
	while((int)i < (int)len - x)
	{
		rslt[i] = ft_strdup(argv[i]);
		i++;
	}
	rslt[(int)len - x] = NULL;
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
	while (yolo[0] != NULL)
	{
		//ft_putstr("----------");
		//ft_putmap(yolo);
		//ft_putstr("----------");
		if(ft_strstrlen(yolo) != 0)
		{
			if(x != 0)
				ft_putchar('\n');
			ft_putstr(yolo[0]);
			ft_putstr(":\n");
		}
		if((list = init(ft_lsargv(yolo[0]), list)) != NULL)
		{
			list = ft_lsttime(list);
			list = ft_lstalpha(list);
			yolo = print(list, yolo);
		}
		else
			exit(-1);
		ft_free(list);
		//list = (liste*)malloc(sizeof(liste));
		x++;
	}
	return (0);
}
