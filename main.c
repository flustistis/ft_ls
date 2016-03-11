#include "ft_ls.h"

liste		*init(char *argv, liste *list)
{
	t_file *filetmp;
	DIR *actualdir;
	struct dirent *myfile;

	filetmp = (t_file*)malloc(sizeof(t_file));
	filetmp->name = NULL;
	if (!(actualdir = opendir(argv)))
	{
		perror("a.out:");
		return (NULL);
	}
	myfile = readdir(actualdir);
	if((list->option_a == 1) || (list->option_a == 0 && myfile->d_name[0] != '.'))
		filetmp = ft_newfile(argv, myfile, list);
	while ((myfile = readdir(actualdir)) && filetmp)
	{
		if((list->option_a == 1) || (list->option_a == 0 && myfile->d_name[0] != '.'))
		{
			if((filetmp->name))
				filetmp->next = ft_newfile(argv, myfile, list);
			else
				filetmp = ft_newfile(argv, myfile, list);
			if ((filetmp->next))
			{
				filetmp->next->previous = filetmp;
				filetmp = filetmp->next;
			}
		}
	}
	while((filetmp->previous))
		filetmp = filetmp->previous;
	list->first = filetmp;
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

liste *no_option(liste *list)
{
	list->option_l = 0;
	list->option_R = 0;
	list->option_a = 0;
	list->option_r = 0;
	list->option_t = 0;
	return (list);
}

int main(int argc, char **argv)
{
	int i;
	int x;
	liste	*list;
	list = (liste*)malloc(sizeof(liste));
	if(argc >= 1)
	{
		if(countopt(argc, argv) > 0)
			list = ft_option(argc, argv);
		else
			list = no_option(list);
	}
	i = 0;
	x = 1;
	if ((argc - countopt(argc, argv)) == 1)
	{
		list = init("./", list);
		printlist(list);
	}
	else
	{
		while(isoption(argv[x]))
			x++;
		while (x < argc)
		{
			if((list = init(ft_lsargv(argv[x]), list)) != NULL)
			{
				printf("%s:\n", argv[x]);
				printlist(list);
			}
			free(list);
			list = (liste*)malloc(sizeof(liste));
		x++;
		}
	}
	return (0);
}
