#include "ft_ls.h"

char	**ft_strstrrev(char **c)
{
	size_t	len;
	size_t	i;
	char	*temp;
	
	i = 0;
	len = ft_strstrlen(c) - 1;
	while (i <= len / 2)
	{
		temp = NULL;
		temp = c[i];
		c[i] = c[len - i];
		c[len - i] = temp;
		i++;
	}
	return (c);
}
