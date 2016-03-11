/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:07:36 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/11 10:39:12 by gmorer           ###   ########.fr       */
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
	char	*name;
	int		size;
	char	*permission;
	char	type;
	char	*date;
	time_t	time;
	char	*useruid;
	char	*groupuid;
	int		linkno;
	struct s_file	*next;
}					t_file;

typedef struct liste liste;
struct liste
{
	t_file *first;
	int option_l;
	int option_R;
	int option_a;
	int option_r;
	int option_t;
};

int		isoption(char *argv);
int		countopt(int argc, char **argv);
char	*ft_lsargv(char *argv);
t_file	*ft_newfile(char *argv, struct dirent *file, liste *list);
char	*strcatturfu(char *s1, char *s2);
char	*ft_uid(int uid);
char	*ft_gid(int gid);
liste	*ft_option(int argc, char **argv);
liste	*ft_lstalpha(liste *list);

#endif
