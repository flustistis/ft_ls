/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/02/18 14:28:12 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isin(char c, char *str)
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

static char		*ft_option(char **argv)
{
	char		*rslt;
	char		*donnay;
	int			i;
	int			x;

	if (argv[1])
	{
		i = 1;
		x = 1;
		rslt = ft_strnew(1);
		donnay = "LRart";
		if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][i] == '\0'))
			return (NULL);
		while (argv[i] && argv[i][0] == '-')
		{
			x = 1;
			while (argv[i][x] && ft_isin(argv[i][x], donnay))
				rslt = ft_charjoin(rslt, argv[i][x++]);
			if (!(ft_isin(argv[i][x], donnay)) && argv[i][x])
				return ("illegal options");
			i++;
		}
		return (rslt);
	}
	return (NULL);
}
