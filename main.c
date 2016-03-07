#include "ft_ls.h"

liste		*init(char *argv, liste *list)
{
	t_file *filetmp;
	DIR *actualdir;
	struct dirent *myfile;

	if (!(actualdir = opendir(argv)))
	{
		perror("a.out:");
		return (NULL);
	}
	myfile = readdir(actualdir);
	filetmp = ft_newfile(argv, myfile, list);
	list->first = filetmp;
	while ((myfile = readdir(actualdir)) && filetmp)
	{
		filetmp->next = ft_newfile(argv, myfile, list);
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
	printf("yolo\n");
	list = (liste*)malloc(sizeof(liste));
	if(argc >= 1)
	{
		if(countopt(argc, argv) > 0)
		{
			printf("there is option\n");
			list = ft_option(argc, argv);
		}
		else
		{
			printf("no option\n");
			list = no_option(list);
		}
	}
	printf("option passer\n");
	i = 0;
	x = 1;
	if ((argc - countopt(argc, argv)) == 1)
	{
		printf("no arg\n");
		list = init("./", list);
		printlist(list);
	}
	else
	{
		printf("enter in teh infini\n");
		while (x < argc)
		{
			if(!(argv[x][0] == '-' && (argv[x][1])))
			{
				printf("cool %s est un fichier a ls\n", argv[x]);
				list = init(ft_lsargv(argv[x]), list);
				printlist(list);
			}
			x++;
		}
	}
	return (0);
}
