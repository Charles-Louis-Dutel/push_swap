/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:16:09 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/14 19:32:34 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	j;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	return (j);
}

/*int main()
{
	char src[] = "coucou";
	char dest1[10];
	char dest2[10];
	memset(dest1, 'A', 10);
	memset(dest2, 'A', 10);

	__builtin_printf("%ld\n", strlcpy(dest1, src, 0));
	__builtin_printf("%s\n", dest1);
	__builtin_printf("%ld\n", strlcpy(dest2, src, 0));
	__builtin_printf("%s\n", dest2);
}*/
