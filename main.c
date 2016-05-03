/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:13:22 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/03 16:24:26 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_liste	*initlist(t_liste *list)
{
	list->totalsize = 0;
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->maxgidlen = 0;
	list->maxsizelen = 0;
	list->actualdir = NULL;
	list->ok = 1;
	return (list);
}

static t_liste *no_option(t_liste *list)
{
	list->option_l = 0;
	list->option_gr = 0;
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
	t_liste	*list;
	int i;
	char **yolo;

	i = 0;
	argv[argc] = NULL;
	list = (t_liste*)malloc(sizeof(t_liste));
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
	yolo = traitor(yolo, list);
	x = 0;
	while (yolo[0] != NULL)
	{
		//ft_putstr("----------");
		//ft_putmap(yolo);
		//ft_putstr("----------");
		list = init(ft_lsargv(yolo[0]), list);
		x++;
		if(list->ok == 1)
		{
			list = ft_lsttime(list);
			list = ft_lstalpha(list);
			yolo = print(list, yolo);
			if(ft_strstrlen(yolo) != 0)
			{
				if(x != 0)
					ft_putchar('\n');
				if(x != 0 || (x == 0 && ft_strstrlen(yolo) != 1))
				{
				ft_putstr(yolo[0]);
				ft_putstr(":\n");
				}
			}
		}
		else
			yolo = ft_strstrdelfirst(yolo);
		//list = (liste*)malloc(sizeof(liste));
		ft_free(list);
	}
	free(yolo);
	return (0);
}
