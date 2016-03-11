/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/11 10:37:59 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_isin(char c, char *str)
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

	rslt = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	rslt = ft_strcpy(rslt, str);
	rslt[ft_strlen(rslt)] = c;
	return (rslt);
}

int			isoption(char *argv)
{
	if (argv[0] == '-')
		if ((argv[1]))
			return (1);
	return (0);
}

char			*ft_optionstr(int argc, char **argv)
{
	int		y;
	char	*rslt;
	char	*donnay;
	int		i;
	int		x;

	if (argc > 0)
	{
		y = 0;
		i = 1;
		x = 1;
		rslt = ft_strnew(1);
		donnay = "lRart";
		while (isoption(argv[i]))
		{
			x = 1;
			while (argv[i][x] && ft_isin(argv[i][x], donnay))
				rslt = ft_charjoin(rslt, argv[i][x++]);
			if (!(ft_isin(argv[i][x], donnay)) && argv[i][x])
				return (NULL);
			i++;
		}
		return (rslt);
	}
	return (NULL);
}

liste			*ft_option(int argc, char **argv)
{
	char	*str;
	liste	*list;

	if ((list = (liste*)malloc(sizeof(liste))) == NULL)
		return (NULL);
	list->option_l = 0;
	list->option_R = 0;
	list->option_a = 0;
	list->option_r = 0;
	list->option_t = 0;
	str = ft_optionstr(argc, argv);
	if ((ft_isin('l', str)))
		list->option_l = 1;
	if (ft_isin('R', str))
		list->option_R = 1;
	if (ft_isin('a', str))
		list->option_a = 1;
	if (ft_isin('r', str))
		list->option_r = 1;
	if (ft_isin('t', str))
		list->option_t = 1;
	ft_strdel(&str);
	return (list);
}
