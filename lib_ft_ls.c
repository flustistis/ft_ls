/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:19:00 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/23 11:20:50 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*strcatturfu(char *s1, char *s2)
{
	char	*rslt;
	int		i;
	int		j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((rslt = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		rslt[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		rslt[i + j] = s2[j];
		j++;
	}
	rslt[i + j] = '\0';
	return (rslt);
}

char		*ft_uid(int uid)
{
	struct passwd	*yolo;

	if((yolo = getpwuid(uid)))
		return (yolo->pw_name);
	return (NULL);
}

char		*ft_gid(int gid)
{
	struct group	*yolo;

	if((yolo = getgrgid(gid)))
		return (yolo->gr_name);
	return(NULL);
}

int countopt(int argc, char **argv)
{
	int x;

	x = 0;
	if (argc == 0)
		return(0);
	while ((argv[x]) && isoption(argv[x]))
		x++;
	return(x + 1);
}
