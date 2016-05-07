/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:07:36 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/06 14:57:29 by gmorer           ###   ########.fr       */
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
# include <sys/types.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_data
{
	char	linkto[1024];
	time_t	time;
	char	*name;
	char	*permission;
	char	*groupuid;
	char	*useruid;
	char	*date;
	int		major;
	int		minor;
	int		size;
	int		linkno;
	char	type;
}					t_data;

typedef struct		s_file
{
	struct s_file	*previous;
	t_data			*content;
	struct s_file	*next;
}					t_file;

typedef struct		s_liste
{
	DIR		*actualdir;
	char	*initialpath;
	t_file	*first;
	size_t	maxlinklen;
	size_t	maxuidlen;
	size_t	maxgidlen;
	size_t	maxsizelen;
	size_t	maxmajorlen;
	size_t	maxminorlen;
	int		ok;
	int		totalsize;
	int		option_l;
	int		option_gr;
	int		option_a;
	int		option_r;
	int		option_t;
}					t_liste;

int					promptgr(int len, int x, char *name);
char				**traitor(char **argv, t_liste *list);
int					freeMonChainon(t_liste *list, t_file *tmpfile);
char				**redirectfunction(t_data *content, t_liste *list, char **add);
t_file				*remplissage(t_file *rslt, struct stat plop, t_liste *list, char name[256]);
char				**ft_strstralpha(char **argv);
char				**ft_strstrnew(size_t i);
size_t				ft_strstrlen(char **c);
char				**ft_strstrjoin(char **s1, char **s2);
char				**ft_strstradd(char *str, char **tab);
char				**ft_strstrdelfirst(char **c);
char				*nxtfd(char *str1, char *str2);
t_liste				*init(char *argv, t_liste *list);
t_liste				*ft_lsttime(t_liste *list);
char				**print(t_liste *list, char **yolo);
int					ft_free(t_liste *list);
int					isoption(char *argv);
char				*ft_lsargv(char *argv);
t_file				*ft_newfile(char *argv, struct dirent *file, t_liste *list);
char				*strcatturfu(char *s1, char *s2);
char				*ft_uid(unsigned int uid);
char				*ft_gid(unsigned int gid);
t_liste				*ft_option(int argc, char **argv);
t_liste				*ft_lstalpha(t_liste *list);

#endif
