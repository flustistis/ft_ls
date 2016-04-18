/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:07:36 by gmorer            #+#    #+#             */
/*   Updated: 2016/04/18 10:21:05 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H

# include <grp.h>
# include <pwd.h>
# include <dirent.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_file
{
	struct s_file	*previous;
	struct data			*content;
	struct s_file	*next;
}					t_file;

typedef struct data data;
struct data
{
	char	*name;
	int		size;
	char	*permission;
	char	type;
	char	*date;
	time_t	time;
	char	*useruid;
	char	*groupuid;
	int		linkno;
	char	linkto[1024];
};

typedef struct liste liste;
struct liste
{
	char	*initialpath;
	int		totalsize;
	t_file	*first;
	int		option_l;
	int		option_R;
	int		option_a;
	int		option_r;
	int		option_t;
	size_t	maxlinklen;
	size_t	maxuidlen;
	size_t	maxgidlen;
	size_t	maxsizelen;
};

char	**ft_strstrnew(int i);
int		ft_strstrlen(char **c);
char	**ft_strstrjoin(char **s1, char **s2);
char	**ft_strstradd(char *str, char **tab);
char	**ft_strstrdelfirst(char **c);
char	*nxtfd(char *str1, char *str2);
liste	*init(char *argv, liste *list);
liste	*ft_lsttime(liste *list);
char	**print(liste *list, char **yolo);
int		ft_free(liste *list);
int		isoption(char *argv);
char	*ft_lsargv(char *argv);
t_file	*ft_newfile(char *argv, struct dirent *file, liste *list);
char	*strcatturfu(char *s1, char *s2);
char	*ft_uid(int uid);
char	*ft_gid(int gid);
liste	*ft_option(int argc, char **argv);
liste	*ft_lstalpha(liste *list);

#endif
