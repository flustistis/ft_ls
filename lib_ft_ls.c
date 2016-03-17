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

static int testalpha(liste *list)
{
	t_file *tmpfile;

	tmpfile = list->first;
	while((tmpfile->next))
	{
		if (ft_strcmp(tmpfile->content->name, tmpfile->next->content->name) > 0)
			return (0);
		tmpfile = tmpfile->next;
	}
	return (1);
}

liste	*ft_lstalpha(liste *list)
{
	data *tmpdata;;
	t_file *tmpfile;
	while(!(testalpha(list)))
	{
		tmpfile = list->first;
		while((tmpfile->next))
		{
				if (ft_strcmp(tmpfile->content->name, tmpfile->next->content->name) > 0)
				{
					tmpdata = tmpfile->content;
					tmpfile->content = tmpfile->next->content;
					tmpfile->next->content = tmpdata;
				}
			tmpfile = tmpfile->next;
		}
	}
	return (list);
}
