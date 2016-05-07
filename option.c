/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/04 16:34:14 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_isin(char c, char *str)
{
	if (!(str))
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static char		*ft_charjoin(char *str, char c)
{
	char	*rslt;

	rslt = ft_strnew(ft_strlen(str) + 2);
	rslt = ft_strcpy(rslt, str);
	rslt[ft_strlen(rslt)] = c;
	return (rslt);
}

int			isoption(char *argv)
{
	if(argv)
		if(argv[0])
			if (argv[0] == '-')
				if ((argv[1]))
					return (1);
		return (0);
}

static char		*ft_optionstr(int argc, char **argv)
{
	char	*rslt;
	char	*donnay;
	int		i;
	int		x;

	if (argc > 0)
	{
		i = 1;
		x = 1;
		rslt = ft_strnew(1);
		donnay = "lRart";
		while (isoption(argv[i]) && ft_strcmp(argv[i], "--") != 0)
		{
			x = 1;
			while (argv[i][x] && ft_isin(argv[i][x], donnay))
				rslt = ft_charjoin(rslt, argv[i][x++]);
			if (!(ft_isin(argv[i][x], donnay)) && argv[i][x])
			{
				ft_putstr("ft_ls: illegal option -- ");
				ft_putchar(argv[i][x]);
				ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
				exit(-1);
			}
			i++;
		}
		return (rslt);
	}
	return (NULL);
}

t_liste			*ft_option(int argc, char **argv)
{
	char	*str;
	t_liste	*list;

	list = NULL;
	if ((list = (t_liste*)malloc(sizeof(t_liste))) == NULL)
		return (NULL);
	memset(list, 0, sizeof(t_liste));
	//ft_bzero(&list, sizeof(*list));
	list->option_l = 0;
	list->option_gr = 0;
	list->option_a = 0;
	list->option_r = 0;
	list->option_t = 0;
	str = ft_optionstr(argc, argv);
	if ((ft_isin('l', str)))
		list->option_l = 1;
	if (ft_isin('R', str))
		list->option_gr = 1;
	if (ft_isin('a', str))
		list->option_a = 1;
	if (ft_isin('r', str))
		list->option_r = 1;
	if (ft_isin('t', str))
		list->option_t = 1;
	ft_strdel(&str);
	return (list);
}
