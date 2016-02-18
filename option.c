/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/02/18 11:09:29 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isin(char c, char *str)
{
	printf("start ft_isin\n");
	while(*str)
	{
		if(*str == c)
		{
			printf("end ft_isin with a return of 1 for c = %c\n", c);
			return (1);
		}
		str++;
	}
	printf("end of ft_isin with a return of 0 for c = %c\n", c);
	return (0);
}

static char	*ft_charjoin(char *str, char c)
{
	printf("start of ft_charjoin\n");
	char *rslt;

	rslt = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	rslt = ft_strcpy(rslt, str);
	rslt[ft_strlen(rslt)] = c;
	printf("return of ft_charjoin rslt = \"%s\"\n", rslt);
	return (rslt);
}

static char	*ft_option(char **argv)
{
	char *rslt;
	char *donnay;
	int i;
	int x;

	i = 1;
	x = 1;
	printf("test1\n");
	donnay = ft_strnew(1);
	donnay = ft_strjoin(donnay, "LRart");
	printf("test2\n");
	printf("donnay = \"%s\"\n", donnay);
	if (argv[i][0] != '-')
		return ("no arg");
	printf("there is arg\n");
	while ( argv[i] && argv[i][0] == '-')
	{
		x = 1;
		printf("test i = %d\n", i);
		while (argv[i][x] && ft_isin(argv[i][x], donnay))
		{
			printf("test du char :%c\n", argv[i][x]);//debug
			rslt = ft_charjoin(rslt, argv[i][x]);
			x++;
		}
		if (!(ft_isin(argv[i][x], donnay)) && argv[i][x])
		{
			printf("enter in if for illegal option");
			return ("illegal options");
		}
		i++;
	}
	printf("return of ft_option with rslt = \"%s\"\n", rslt);
	return (rslt);
}

int		main(int argc, char **argv)
{
	char *rslt;
	rslt = ft_option(argv);
	printf("ft_option passed\n");
	printf("%s\n", rslt);
	return (0);
}
