/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:07:36 by gmorer            #+#    #+#             */
/*   Updated: 2016/02/21 17:45:15 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H

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
	int		year;
	char	month;
	int		day;
	int		hour;
	int		minutes;
	struct s_file	*next;
}					t_file;


char *ft_option(char **argv);

#endif
