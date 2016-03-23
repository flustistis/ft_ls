#include "ft_ls.h"

liste		*init(char *argv, liste *list)
{
	t_file *filetmp;
	DIR *actualdir;
	struct dirent *myfile;

	if ((filetmp = (t_file*)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if ((filetmp->content = (data*)malloc(sizeof(data))) == NULL)
		return (NULL);
	filetmp->content->name = NULL;
	if (!(actualdir = opendir(argv)))
	{
		perror("a.out:");
		return (NULL);
	}
	if ((myfile = readdir(actualdir)) == NULL)
		return (NULL);
	if ((list->option_a == 1) || (list->option_a == 0 && myfile->d_name[0] != '.'))
		if ((filetmp = ft_newfile(argv, myfile, list)) == NULL)
			return (NULL);
	while ((myfile = readdir(actualdir)) && filetmp)
	{
		if((list->option_a == 1) || (list->option_a == 0 && myfile->d_name[0] != '.'))
		{
			if((filetmp->content->name))
				filetmp->next = ft_newfile(argv, myfile, list);
			else
				filetmp = ft_newfile(argv, myfile, list);
			if ((filetmp->next))
			{
				filetmp->next->previous = filetmp;
				filetmp = filetmp->next;
			}
		}
	}/*
	if (myfile == NULL)
	{
		printf("return NULL a la fin du while\n");
		return (NULL);
	}*/
	while((filetmp->previous))
		filetmp = filetmp->previous;
	list->first = filetmp;
	return (list);
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
	while(isoption(argv[x]))
		x++;
	if (x == argc)
	{
		if ((list = init("./", list)) == NULL)
		{
			printf("return NULL on init\n");
			return (0);
		}
		list = ft_lsttime(list);
		list = ft_lstalpha(list);
		print(list);
		ft_free(list);
	}
	else
	{
		while (x < argc)
		{
			if((list = init(ft_lsargv(argv[x]), list)) != NULL)
			{
				printf("%s:\n", argv[x]);
				list = ft_lsttime(list);
				list = ft_lstalpha(list);
				print(list);
			}
			else
			{
				printf("return null on init\n");
				return (0);
			}
				ft_free(list);
			list = (liste*)malloc(sizeof(liste));
		x++;
		}
	}
	return (0);
}
