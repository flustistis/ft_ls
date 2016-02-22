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

char type(char *fd)
{
	int mode;
	struct stat plop;

	lstat(fd, &plop);
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

int			main(int argc, char **argv)
{
	t_file *swag;
	DIR		*actualdir;
	struct dirent *myfile;
	struct stat yolo;

	if(!(actualdir = opendir(argv[1])))
	{
		perror("test opendir :");
		return (0);
	}
	while ((myfile = readdir(actualdir)))
	{
		stat(myfile->d_name, &yolo);
		printf("type :%c,  size : %lld,  name :%s\n", type(myfile->d_name),yolo.st_size , myfile->d_name);
	}
	return (0);
}
