/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:58:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/06 15:13:14 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strstrlen(char **c)
{
	int i;

	i = 0;
	while(c[i] != NULL)
		i++;
	return (i);
}

char	**ft_strstrjoin(char **s1, char **s2)
{
	char **rslt;
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	if(!s2)
		return (s1);
	if(!s1)
		return (s2);
	if(!(rslt = (char**)malloc(sizeof(char*) * (ft_strstrlen(s1) + ft_strstrlen(s2) - 1))))
		return (NULL);
	while(s1[i1] != NULL)
	{
		rslt[i1] = s1[i1];
		i1++;
	}
	while(s2[i2] != NULL)
	{
		rslt[i1 + i2 - 1] = s2[i2];
		i2++;
	}
	rslt[i1 + i2 - 1] = NULL;
	return (rslt);
}

char	**ft_strstradd(char *str, char **tab)
{
	char **rslt;
	int i;

	i = 0;
	if(!(rslt = (char**)malloc(sizeof(char*) * (ft_strstrlen(tab) + 1))))
		return (NULL);
	while(tab[i] != NULL)
	{
		rslt[i] = tab[i];
		i++;
	}
	rslt[i] = str;
	return(rslt);
}

char	**ft_strstrdelfirst(char **c)
{
	char	**rslt;
	int 	i;

	if(!(rslt = (char**)malloc(sizeof(char*) * (ft_strstrlen(c) - 1))))
		return (NULL);
	i = 1;
	while(c[i] != NULL)
	{
		rslt[i - 1] = c[i];
		i++;
	}
	rslt[i - 1] = NULL;
	return (rslt);
}
