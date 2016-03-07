#include "ft_ls.h"

liste		*init(char *argv)
{
	liste *list;
	t_file *filetmp;
	DIR *actualdir;
	struct dirent *myfile;

	list = (liste*)malloc(sizeof(liste));
	if (!(actualdir = opendir(argv)))
	{
		perror("a.out:");
		return (NULL);
	}
	myfile = readdir(actualdir);
	filetmp = ft_newfile(argv, myfile);
	list->first = filetmp;
	while ((myfile = readdir(actualdir)) && filetmp)
	{
		filetmp->next = ft_newfile(argv, myfile);
		if ((filetmp->next))
		{
			filetmp->next->previous = filetmp;
			filetmp = filetmp->next;
		}
	}
	return (list);
}

void	printlist(liste *list)
{
	t_file	*filetmp;

	filetmp = list->first;
	printf("%c%s %d %s %s %d %s %s\n", filetmp->type, filetmp->permission, filetmp->linkno, filetmp->useruid, filetmp->groupuid, filetmp->size, filetmp->date, filetmp->name);
	while((filetmp = filetmp->next))
		printf("%c%s %d %s %s %d %s %s\n", filetmp->type, filetmp->permission, filetmp->linkno, filetmp->useruid, filetmp->groupuid, filetmp->size, filetmp->date, filetmp->name);
	return ;
}

int main(int argc, char **argv)
{
	liste	*list;

	list = ft_option(argc, argv);
	if (argc == 0)
		list = init("./");
	else
		list = init(ft_lsargv(argv[1]));
	printlist(list);
	return (0);
}
