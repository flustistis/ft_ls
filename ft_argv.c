#include "ft_ls.h"

char	*ft_lsargv(char *argv)
{
	if ((argv))
	{
		if (ft_strcmp(argv,".") == 0)
			return ("./");
		else if (argv[ft_strlen(argv) - 1] != '/')
			return(strcatturfu(argv, "/"));
		else
			return (argv);
	}
	return ("./");
}
