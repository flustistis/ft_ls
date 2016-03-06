/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/02/21 13:38:46 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_isin(char c, char *str)
{
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
	char		*rslt;

	rslt = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	rslt = ft_strcpy(rslt, str);
	rslt[ft_strlen(rslt)] = c;
	return (rslt);
}

int		isoption(char *argv)
{
	if(argv[0] == '-')
		if((argv[1]))
			return (1);
	return (0);
}

char			*ft_option(int argc, char **argv)
{
	int			y;
	char		*rslt;
	char		*donnay;
	int			i;
	int			x;

	if (argc > 0)
	{
		y = 0;
		i = 1;
		x = 1;
		rslt = ft_strnew(1);
		donnay = "LRart";
		while (y <= argc)
		{
			x = 1;
			if (isoption(argv[y]))
			{
				while (argv[i][x] && ft_isin(argv[i][x], donnay))
					rslt = ft_charjoin(rslt, argv[i][x++]);
				if (!(ft_isin(argv[i][x], donnay)) && argv[i][x])
					return (NULL);
			}
		}
		return (rslt);
	}
	return (NULL);
}
