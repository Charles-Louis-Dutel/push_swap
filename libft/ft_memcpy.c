/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:21:12 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/14 16:28:32 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	const char		*source;
	char			*destination;

	if (!dest && !src)
		return (NULL);
	source = (const char *)src;
	destination = (char *)dest;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char *src1 = "";
	char *src2 = "";
	char *dest1 = NULL;
	char *dest2 = NULL;
	int length = 3;


	length = sizeof( char ) * 0;
	dest1 = (char *) malloc( length );
	memcpy(dest1, src1, length);
	for(length=0; length<9; length++)
		__builtin_printf("%c ", dest1[length]);
	__builtin_printf("\n");

	length = sizeof( char ) * 0;
	dest2 = (char *) malloc( length );
	ft_memcpy(dest2, src2, length);
	for(length=0; length<9; length++)
		__builtin_printf("%c ", dest2[length]);
	__builtin_printf("\n");

	return(0);
}*/
