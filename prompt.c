#include "ft_ls.h"

int		promptgr(int len, int x, char *name)
{
	if(len != 0)
	{
		if(x != 0)
			ft_putchar('\n');
		if(x != 0 || (x == 0 && len != 1))
		{
			ft_putstr(name);
			ft_putstr(":\n");
			x++;
		}
	}
	return (x);
}


