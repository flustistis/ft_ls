/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:08:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/07 12:40:01 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isin(char c, char *str)
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

char	*ft_option(int argc, char **argv)
{
	char *rslt;
	char *donnay;
	int i;
	int x;
	int count;

	count = countopt(argc, argv);
	printf("option number = %d\n", count);
	if(count == 0)
		return(NULL);
	i = 0;
	x = 1;
	argc = 0;
	printf("test1\n");
	rslt = ft_strnew(1);
	donnay = "lRart-";
	printf("test2\n");
	printf("donnay = \"%s\"\n", donnay);
	while  (argc < count && (x = 1))
		if (argv[++i][0] == '-' && (argv[i][1]))
		{
			while ((argv[i][x]) && ft_isin(argv[i][x], donnay))
			{
				printf("test du char :%c\n", argv[i][x]);//debug
				rslt = ft_charjoin(rslt, argv[i][x++]);
			}
			if ((argv[i][x]) && !(ft_isin(argv[i][x], donnay)))
			{
				printf("enter in if for illegal option");
				return ("illegal options");
			}
			argc++;
		}
		//printf("end of the while\n");
	printf("return of ft_option with rslt = \"%s\"\n", rslt);
	return (rslt);
}

int		main(int argc, char **argv)
{
	if(argc > 0)
	{
		char *rslt;
		rslt = ft_option(argc, argv);
		//printf("rslt[0] = \"%c\"\n", rslt[0]);
		printf("ft_option passed\n");
		printf("%s\n", rslt);
	}
	return (0);
}
