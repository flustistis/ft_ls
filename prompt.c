/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:35:42 by gmorer            #+#    #+#             */
/*   Updated: 2016/05/13 11:32:50 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		promptgr(int len, int x, char *name)
{
	if (len != 0)
	{
		if (x != 0)
			ft_putchar('\n');
		if (x != 0 || (x == 0 && len != 1))
		{
			ft_putstr(name);
			ft_putstr(":\n");
			x++;
		}
	}
	return (x);
}

t_liste	*testifl(t_file *rslt, t_liste *list, char *temp)
{
	temp = ft_itoa(rslt->content->linkno);
	if (ft_strlen(temp) > list->maxlinklen)
		list->maxlinklen = ft_strlen(temp);
	free(temp);
	if (ft_strlen(rslt->content->groupuid) > list->maxgidlen)
		list->maxgidlen = ft_strlen(rslt->content->groupuid);
	if (ft_strlen(rslt->content->useruid) > list->maxuidlen)
		list->maxuidlen = ft_strlen(rslt->content->useruid);
	temp = ft_itoa(rslt->content->size);
	if (ft_strlen(temp) > list->maxsizelen)
		list->maxsizelen = ft_strlen(temp);
	free(temp);
	temp = ft_itoa(rslt->content->major);
	if (ft_strlen(temp) > list->maxmajorlen)
		list->maxmajorlen = ft_strlen(temp);
	free(temp);
	temp = ft_itoa(rslt->content->minor);
	if (ft_strlen(temp) > list->maxminorlen)
		list->maxminorlen = ft_strlen(temp);
	free(temp);
	if (rslt->content->type == 'l')
		ft_memset(rslt->content->linkto, 0, 1024);
	return (list);
}
