/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:57:23 by gmorer            #+#    #+#             */
/*   Updated: 2016/02/22 16:10:57 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char ft_type(struct stat plop)
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
	return('e');
}

char	*permission(struct stat plop)
{
	char *rslt;

	rslt = ft_strnew(9);
	ft_memset(rslt, '-', 9);
	rslt[9] = '\0';
	if(plop.st_mode&S_IRUSR)
		rslt[0] = 'r';
	if(plop.st_mode&S_IWUSR)
		rslt[1] = 'w';
	if(plop.st_mode&S_IXUSR)
		rslt[2] = 'x';
	if(plop.st_mode&S_IRGRP)
		rslt[3] = 'r';
	if(plop.st_mode&S_IWGRP)
		rslt[4] = 'w';
	if(plop.st_mode&S_IXGRP)
		rslt[5] = 'x';
	if(plop.st_mode&S_IROTH)
		rslt[6] = 'r';
	if(plop.st_mode&S_IWOTH)
		rslt[7] = 'w';
	if(plop.st_mode&S_IXOTH)
		rslt[8] = 'x';
	return (rslt);
}

char	*ft_timels(char *time)
{
	char	*rslt;
	int		i;

	i = 0;
	rslt = (char*)malloc(sizeof(char) * 13);
	while (*time != ' ')
		*time++;
	*time++;
	while(i < 12)
	{
		rslt[i] = *time;
		i++;
		*time++;
	}
	rslt[12] = '\0';
	return (rslt);
}


t_file	*ft_newfile(char *argv, struct dirent *file)
{
	t_file *rslt;
	struct stat plop;
	time_t time;
	char *test;

	if(lstat(strcatturfu(argv, file->d_name), &plop) == -1)
	{
		perror("error stat:");
		printf("error with the file name : %s\n", file->d_name);
		return (NULL);
	}
	if (!(rslt = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	if (!(file))
		return (NULL);
	test = ctime(&plop.st_mtime);
	rslt->permission = permission(plop);
	rslt->name = file->d_name;
	rslt->type = ft_type(plop);
	rslt->size = plop.st_size;
	rslt->linkno = plop.st_nlink;
	rslt->time = plop.st_mtime;
	rslt->date = ft_timels(ctime(&plop.st_mtime));
	rslt->next = NULL;
	rslt->useruid = ft_uid(plop.st_uid);
	rslt->groupuid = ft_gid(plop.st_gid);
	rslt->previous = NULL;

	return (rslt);
}
/*
int			main(int argc, char **argv)
{
	liste *list;
	t_file *filetmp;
	DIR		*actualdir;
	struct dirent *myfile;

	list = (liste*)malloc(sizeof(liste));
	if(!(actualdir = opendir(argv[1])))
	{
		perror("test opendir :");
		return (0);
	}
	myfile = readdir(actualdir);
	filetmp = ft_newfile(argv[1], myfile);
	list->first = filetmp;
	while ((myfile = readdir(actualdir)) && filetmp)
	{
		filetmp->next = ft_newfile(argv[1], myfile);
		if ((filetmp->next))
		{
			filetmp->next->previous = filetmp;
			filetmp = filetmp->next;
		}
	}
	
	printf("%c%s %d %s %s %d %s %s\n", filetmp->type, filetmp->permission, filetmp->linkno, filetmp->useruid, filetmp->groupuid, filetmp->size, filetmp->date, filetmp->name);
	while ((filetmp = filetmp->previous))
		printf("%c%s %d %s %s %d %s %s\n", filetmp->type, filetmp->permission, filetmp->linkno, filetmp->useruid, filetmp->groupuid, filetmp->size, filetmp->date, filetmp->name);
return (0);
}
*/
