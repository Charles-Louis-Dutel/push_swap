/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:48:48 by cdutel            #+#    #+#             */
/*   Updated: 2023/10/31 15:54:07 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int main()
{
	//char s[] = "tripouille";
	//char s2[] = "ltripouiel";
	char s3[] = "";

	__builtin_printf("%s\n", strrchr(s3, 0));
	__builtin_printf("%s\n", ft_strrchr(s3, 0));
	return 0;
}*/
