/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:57:23 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/19 14:22:11 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			ft_type(struct stat plop)
{
	if ((S_ISLNK(plop.st_mode)))
		return ('l');
	else if ((S_ISSOCK(plop.st_mode)))
		return ('s');
	else if ((S_ISCHR(plop.st_mode)))
		return ('c');
	else if ((S_ISBLK(plop.st_mode)))
		return ('b');
	else if ((S_ISFIFO(plop.st_mode)))
		return ('p');
	else if ((S_ISDIR(plop.st_mode)))
		return ('d');
	else if ((S_ISREG(plop.st_mode)))
		return ('-');
	return ('e');
}

static char		*permission(struct stat plop)
{
	char *rslt;

	rslt = ft_strnew(9);
	ft_memset(rslt, '-', 9);
	rslt[9] = '\0';
	if (plop.st_mode & S_IRUSR)
		rslt[0] = 'r';
	if (plop.st_mode & S_IWUSR)
		rslt[1] = 'w';
	if (plop.st_mode & S_IXUSR)
		rslt[2] = 'x';
	if (plop.st_mode & S_IRGRP)
		rslt[3] = 'r';
	if (plop.st_mode & S_IWGRP)
		rslt[4] = 'w';
	if (plop.st_mode & S_IXGRP)
		rslt[5] = 'x';
	if (plop.st_mode & S_IROTH)
		rslt[6] = 'r';
	if (plop.st_mode & S_IWOTH)
		rslt[7] = 'w';
	if (plop.st_mode & S_IXOTH)
		rslt[8] = 'x';
	return (rslt);
}

t_file			*remplissageforl(t_file *rslt, t_liste *list, struct stat plop)
{
	if ((list->option_l))
	{
		rslt->content->permission = permission(plop);
		rslt->content->linkno = (int)plop.st_nlink;
		rslt->content->groupuid = ft_gid(plop.st_gid);
		rslt->content->useruid = ft_uid(plop.st_uid);
		rslt->content->size = (int)plop.st_size;
		if (rslt->content->type == 'b' || rslt->content->type == 'c')
		{
			rslt->content->major = (int)major(plop.st_rdev);
			rslt->content->minor = (int)minor(plop.st_rdev);
		}
		else
		{
			rslt->content->major = 0;
			rslt->content->minor = 0;
		}
	}
	return (rslt);
}

char			*ft_timels(char *time)
{
	char	*rslt;
	int		i;

	i = 0;
	if ((rslt = (char*)malloc(sizeof(char) * 13)) == 0)
		return (NULL);
	while (*time != ' ')
		time++;
	time++;
	while (i < 12)
	{
		rslt[i] = *time;
		i++;
		time++;
	}
	rslt[12] = '\0';
	return (rslt);
}

t_file			*ft_newfile(char *argv, char name[256], t_liste *list)
{
	t_file		*rslt;
	struct stat	plop;
	char		*temp;

	temp = nxtfd(argv, name);
	if (lstat(temp, &plop) == -1)
	{
		temp = ft_strjoin("ft_ls :", temp);
		perror(temp);
		free(temp);
		return (NULL);
	}
	free(temp);
	if (!(rslt = (t_file*)malloc(sizeof(t_file))) ||
			!(rslt->content = (t_data*)malloc(sizeof(t_data))) || !(name))
		return (NULL);
	rslt = remplissage(rslt, plop, list, name);
	list->totalsize += (int)plop.st_blocks;
	if ((list->option_l))
		list = testifl(rslt, list, temp);
	if ((list->option_l))
		rslt->content->type == 'l' ? readlink(ft_strjoin(argv, name),
				rslt->content->linkto, sizeof(rslt->content->linkto) - 1) : 0;
	return (rslt);
}
