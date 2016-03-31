#include "ft_ls.h"

liste	*initlist(liste *list)
{
	list->totalsize = 0;
	list->maxlinklen = 0;
	list->maxuidlen = 0;
	list->maxgidlen = 0;
	list->maxsizelen = 0;
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
	int x;
	liste	*list;

	list = (liste*)malloc(sizeof(liste));
	list = initlist(list);
	if(argc >= 1)
	{
		if(countopt(argc, argv) > 0)
			list = ft_option(argc, argv);
		else
			list = no_option(list);
	}
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
