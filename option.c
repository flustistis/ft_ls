/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/07 16:27:18 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_isin(char c, char *str)
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

static char	*ft_charjoin(char *str, char c)
{
	char	*rslt;

	rslt = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	rslt = ft_strcpy(rslt, str);
	rslt[ft_strlen(rslt)] = c;
	return (rslt);
}

static char	*ft_optionstr(int argc, char **argv)
{
	char	*rslt;
	char	*donnay;
	int		i;
	int		x;
	int		count;

	if ((count = countopt(argc, argv)) == 0)
		return (NULL);
	x = 1;
	i = 0;
	argc = 0;
	rslt = ft_strnew(1);
	donnay = "lRar-t";
	while (argc < count && (x = 1))
		if (argv[++i][0] == '-' && (argv[i][1]))
		{
			while ((argv[i][x]) && ft_isin(argv[i][x], donnay))
				rslt = ft_charjoin(rslt, argv[i][x++]);
			if ((argv[i][x]) && !(ft_isin(argv[i][x], donnay)))
				return ("illegal options");
			argc++;
		}
	return (rslt);
}

liste		*ft_option(int argc, char **argv)
{
	liste *list;
	list = (liste*)malloc(sizeof(liste));
	char	*str;
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
