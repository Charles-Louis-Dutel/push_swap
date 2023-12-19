/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 11:44:42 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct p_list
{
	char			*data;
	struct p_list	*next;
}	my_list;

char	*get_next_line(int fd);
char	*ft_new_line(my_list *temp);
void	ft_new_temp(my_list **temp);
my_list	*ft_get_last(my_list *temp);
void	ft_free_list(my_list *temp);
int		ft_stlen(char *s);

#endif
