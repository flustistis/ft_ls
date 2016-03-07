#include "ft_ls.h"

char		*strcatturfu(char *s1, char *s2)
{
	char	*rslt;
	int		i;

	i = 0;
	rslt = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	while ((*s1))
	{
		rslt[i] = *s1;
		s1++;
		i++;
	}
	while ((*s2))
	{
		rslt[i] = *s2;
		s2++;
		i++;
	}
	rslt[i] = '\0';
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
	int i;
	int x;

	x = 0;
	i = 0;
	if (argc == 0)
		return(0);
	while (x < argc)
	{
		if(argv[x][0] == '-')
		{
		if((argv[x][1]))
			i++;
		}
		//printf("x = %d\n", x);
		x++;
	}
	return(i);
}















